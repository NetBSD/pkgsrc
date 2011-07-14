# $NetBSD: builtin.mk,v 1.2 2011/07/14 18:06:59 drochner Exp $

BUILTIN_PKG:=	mpfr

PKGCONFIG_FILE.mpfr=	/usr/include/mpfr.h
PKGCONFIG_BASE.mpfr=	/usr

BUILTIN_VERSION_SCRIPT.mpfr= ${AWK} \
	'/\#define[ \t]*MPFR_VERSION_STRING[ \t]/ { \
	v = substr($$3, 2, length($$3)-2) } \
	END { gsub("-p",".",v); print v }'

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
