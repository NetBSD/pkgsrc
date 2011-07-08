# $NetBSD: builtin.mk,v 1.1 2011/07/08 09:40:57 drochner Exp $

BUILTIN_PKG:=	mpcomplex

PKGCONFIG_FILE.mpcomplex=	/usr/include/mpc.h
PKGCONFIG_BASE.mpcomplex=	/usr

BUILTIN_VERSION_SCRIPT.mpcomplex= ${AWK} \
	'/\#define[ \t]*MPC_VERSION_STRING[ \t]/ { \
	v = substr($$3, 2, length($$3)-2); } \
	END { print v; }'

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
