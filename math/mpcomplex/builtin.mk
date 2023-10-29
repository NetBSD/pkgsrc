# $NetBSD: builtin.mk,v 1.3 2023/10/29 18:06:32 wiz Exp $

BUILTIN_PKG:=	mpcomplex

PKGCONFIG_FILE.mpcomplex=	/usr/include/mpc.h
PKGCONFIG_BASE.mpcomplex=	/usr

BUILTIN_VERSION_SCRIPT.mpcomplex=	${AWK} \
					'/\#define[ \t]*MPC_VERSION_STRING[ \t]/ { \
					v = substr($$3, 2, length($$3)-2); } \
					END { print v; }'

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
