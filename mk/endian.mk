# $NetBSD: endian.mk,v 1.1 2002/04/22 02:30:51 jlam Exp $
#
# Determine the endianness of the platform by checking header files.
#
# This file is used as follows:
#
# .include "../../mk/endian.mk"
#
# .if ${MACHINE_ENDIAN} == "big"
# # ...big endian stuff...
# .elif ${MACHINE_ENDIAN} == "little"
# # ...little endian stuff...
# .else
# BROKEN=	"Unknown endianness"
# .endif

.include "../../mk/bsd.prefs.mk"
.if !defined(MACHINE_ENDIAN)
_ENDIAN_H_FILES=	/usr/include/endian.h		# Linux
_ENDIAN_H_FILES+=	/usr/include/sys/endian.h	# NetBSD=>1.5
_ENDIAN_H_FILES+=	/usr/include/machine/endian.h	# NetBSD<1.5
_ENDIAN_H_FILES+=	/usr/include/sys/byteorder.h	# Solaris
_ENDIAN_H_FILES+=	/dev/null
.  for FILE in ${_ENDIAN_H_FILES}
.    if !defined(_ENDIAN_H)
.      if exists(${FILE})
_ENDIAN_H?=		${FILE:S/\/usr\/include\///}
.      endif
.    endif
.  endfor
MACHINE_ENDIAN!=							\
	byte_order=`							\
		(							\
			${ECHO} "\#include <${_ENDIAN_H}>";		\
			${ECHO} "\#ifndef BYTE_ORDER";			\
			${ECHO} "\#ifdef _BIG_ENDIAN";			\
			${ECHO} "\#define BYTE_ORDER 4321";		\
			${ECHO} "\#else";				\
			${ECHO} "\#define BYTE_ORDER 1234";		\
			${ECHO} "\#endif";				\
			${ECHO} "\#endif";				\
			${ECHO} "BYTE_ORDER";				\
		) | ${CC} -E - | ${GREP} "^\\(1234\\|4321\\)"		\
	`;								\
	case `${ECHO} $${byte_order}` in				\
	1234)	${ECHO} little ;;					\
	4321)	${ECHO} big ;;						\
	*)	${ECHO} unknown ;;					\
	esac
MAKEFLAGS+=	MACHINE_ENDIAN="${MACHINE_ENDIAN}"
.endif
