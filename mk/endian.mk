# $NetBSD: endian.mk,v 1.4 2005/04/30 03:01:06 jlam Exp $
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
.  if exists(/usr/include/endian.h)
_ENDIAN_H=	/usr/include/endian.h		# Linux
.  elif exists(/usr/include/sys/endian.h)
_ENDIAN_H=	/usr/include/sys/endian.h	# NetBSD>=1.5
.  elif exists(/usr/include/machine/endian.h)
_ENDIAN_H=	/usr/include/machine/endian.h	# NetBSD<1.5
.  elif exists(/usr/include/sys/byteorder.h)
_ENDIAN_H=	/usr/include/sys/byteorder.h	# Solaris
.  else
_ENDIAN_H=	/dev/null
.  endif

MACHINE_ENDIAN!=							\
	{ ${ECHO} "\#include <${_ENDIAN_H}>";				\
	  ${ECHO} "\#ifndef BYTE_ORDER";				\
	  ${ECHO} "\#ifdef _BIG_ENDIAN";				\
	  ${ECHO} "\#define BYTE_ORDER 4321";				\
	  ${ECHO} "\#else";						\
	  ${ECHO} "\#define BYTE_ORDER 1234";				\
	  ${ECHO} "\#endif";						\
	  ${ECHO} "\#endif";						\
	  ${ECHO} "BYTE_ORDER"; } | ${CC} -E - |			\
	{ while read line; do						\
		case $$line in						\
		1234)	${ECHO} "little"; exit 0 ;;			\
		4321)	${ECHO} "big"; exit 0 ;;			\
		esac;							\
	  done;								\
	  ${ECHO} "unknown"; }

MAKEFLAGS+=	MACHINE_ENDIAN=${MACHINE_ENDIAN:Q}
.endif
