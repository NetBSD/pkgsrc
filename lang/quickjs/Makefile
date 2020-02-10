# $NetBSD: Makefile,v 1.5 2020/02/10 13:06:08 he Exp $

NAME=		quickjs
QJS_DATE=	2020-01-19
VERSION=	${QJS_DATE:S/-//g}
DISTNAME=	${NAME}-${QJS_DATE}
PKGNAME=	${NAME}-${VERSION}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://bellard.org/quickjs/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bellard.org/quickjs/
COMMENT=	Quick JavaScript interpreter
LICENSE=	mit

USE_TOOLS+=	gmake
MAKE_FLAGS=	prefix=${PREFIX}
TEST_TARGET=	test

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	lto

.if ${OPSYS} == "NetBSD"
HAS_ATOMIC_64!=	${CC} -E files/netbsd-has-atomic64.c | tail -1
.if (${HAS_ATOMIC_64} == "YES")
MAKE_ENV+=	CONFIG_BIGNUM=yes
.endif
.elif ${OPSYS} == "Linux"
PLIST.lto=yes
.else # Not NetBSD && not Linux
# Presumed to be supported
MAKE_ENV+=	CONFIG_BIGNUM=yes
.endif

.include "../../mk/bsd.pkg.mk"
