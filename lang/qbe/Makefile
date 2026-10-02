# $NetBSD: Makefile,v 1.4 2026/10/02 20:15:03 charlotte Exp $

DISTNAME=	qbe-1.3
CATEGORIES=	lang
MASTER_SITES=	https://c9x.me/compile/release/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://c9x.me/compile/
COMMENT=	Compiler backend
LICENSE=	mit

CONFLICTS+=	qbe-git-[0-9]*

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

BUILD_TARGET=	qbe
TEST_TARGET=	check

INSTALL_MAKE_FLAGS+=	BINDIR=${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
