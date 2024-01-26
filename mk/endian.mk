# $NetBSD: endian.mk,v 1.11 2024/01/26 03:16:58 riastradh Exp $
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

.include "../../mk/compiler.mk"

.if !defined(MACHINE_ENDIAN)
BUILTIN_FIND_HEADERS_VAR:=	_ENDIAN_H
BUILTIN_FIND_HEADERS._ENDIAN_H=	endian.h sys/endian.h machine/endian.h \
				sys/byteorder.h
.include "../../mk/buildlink3/find-headers.mk"
.  if !empty(_ENDIAN_H:M__nonexistent__)
_ENDIAN_H=	/dev/null
.  endif

_MACHINE_ENDIAN_CPP=	${CCPATH:U${CC}} -E -
.if ${TOOLS_USE_CROSS_COMPILE:tl} == "yes"
_MACHINE_ENDIAN_CPP+=	--sysroot=${TOOLS_CROSS_DESTDIR:Q}
.endif

MACHINE_ENDIAN!=							\
	{ ${ECHO} "\#if defined(__sgi)";				\
	  ${ECHO} "\#  include <standards.h>";				\
	  ${ECHO} "\#endif";						\
	  ${ECHO} "\#include <${_ENDIAN_H}>";				\
	  ${ECHO} "\#ifndef BYTE_ORDER";				\
	  ${ECHO} "\#ifdef _BIG_ENDIAN";				\
	  ${ECHO} "\#define BYTE_ORDER 4321";				\
	  ${ECHO} "\#else";						\
	  ${ECHO} "\#define BYTE_ORDER 1234";				\
	  ${ECHO} "\#endif";						\
	  ${ECHO} "\#endif";						\
	  ${ECHO} "BYTE_ORDER"; } | ${_MACHINE_ENDIAN_CPP} |		\
	{ while read line; do						\
		case $$line in						\
		1234)	${ECHO} "little"; exit 0 ;;			\
		4321)	${ECHO} "big"; exit 0 ;;			\
		esac;							\
	  done;								\
	  ${ECHO} "unknown"; }

MAKEFLAGS+=	MACHINE_ENDIAN=${MACHINE_ENDIAN:Q}
.endif
