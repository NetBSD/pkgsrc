# $NetBSD: hacks.mk,v 1.1 2025/06/02 11:16:24 vins Exp $

.if !defined(MXKILL_HACKS_MK)
MXKILL_HACKS_MK=	defined

# Package provides no configure script.
# Hence we define platform-dependent includes here.
.if exists(/usr/include/string.h)
PKG_HACKS+=	string.h
CFLAGS+=	-DHAVE_STRING_H
.endif
.if exists(/usr/include/stdlib.h)
PKG_HACKS+=	malloc
CFLAGS+=	-DSTDC_HEADERS -DREGEX_MALLOC
.endif

.endif	# MXKILL_HACKS_MK
