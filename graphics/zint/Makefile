# $NetBSD: Makefile,v 1.13 2026/02/16 13:10:34 wiz Exp $

DISTNAME=	zint-2.16.0-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.zint.org.uk/
COMMENT=	Open source barcode generating solution
#LICENSE=	BSD and GPL

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DMAN_INSTALL_DIR=${PREFIX}/${PKGMANDIR}

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
