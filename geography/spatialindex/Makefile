# $NetBSD: Makefile,v 1.1 2015/11/27 17:51:58 adam Exp $

DISTNAME=	spatialindex-src-1.8.5
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	geography
MASTER_SITES=	http://download.osgeo.org/libspatialindex/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libspatialindex.github.io/
COMMENT=	Robust spatial indexing methods
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	src/libspatialindex.pc.in

.include "../../mk/bsd.pkg.mk"
