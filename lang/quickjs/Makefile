# $NetBSD: Makefile,v 1.2 2020/01/26 18:37:49 he Exp $

DISTNAME=	quickjs-2020-01-19
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

.include "../../mk/bsd.pkg.mk"
