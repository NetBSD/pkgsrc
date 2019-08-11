# $NetBSD: Makefile,v 1.50 2019/08/11 13:21:08 wiz Exp $

DISTNAME=	enblend-enfuse-4.2
PKGREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=enblend/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://enblend.sourceforge.net/
COMMENT=	Combines overlapping images without seams, with good exposure
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl:build pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		GNUPLOT=false

BUILD_DEPENDS+=		help2man-[0-9]*:../../converters/help2man

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--with-x
.include "../../graphics/glut/buildlink3.mk"
.endif

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/vigra/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
