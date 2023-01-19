# $NetBSD: Makefile,v 1.1 2023/01/19 02:20:00 charlotte Exp $

DISTNAME=	qbe-1.0
CATEGORIES=	lang
MASTER_SITES=	https://c9x.me/git/qbe.git/snapshot/

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
