# $NetBSD: Makefile,v 1.1 2019/11/14 21:20:04 rillig Exp $

DISTNAME=	quickjs-2019-10-27
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
