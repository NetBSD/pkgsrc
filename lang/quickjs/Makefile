# $NetBSD: Makefile,v 1.3 2020/01/26 19:04:43 he Exp $

NAME=		quickjs
DATE=		2020-01-19
VERSION=	${DATE:S/-//g}
DISTNAME=	${NAME}-${DATE}
PKGNAME=	${NAME}-${VERSION}
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

PLIST_VARS+=	bignum
.if ${OPSYS} == "NetBSD"
HAS_ATOMIC_64!=	${CC} -E files/netbsd-has-atomic64.c | tail -1
.if (${HAS_ATOMIC_64} == "YES")
PLIST.bignum	= yes
.endif
.else # Not NetBSD
PLIST.bignum	= yes
.endif

.include "../../mk/bsd.pkg.mk"
