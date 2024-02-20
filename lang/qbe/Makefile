# $NetBSD: Makefile,v 1.3 2024/02/20 22:20:50 charlotte Exp $

DISTNAME=	qbe-1.2
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

INSTALL_MAKE_FLAGS+=	BINDIR=${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
