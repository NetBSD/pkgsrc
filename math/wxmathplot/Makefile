# $NetBSD: Makefile,v 1.18 2025/08/30 22:45:51 wiz Exp $

DISTNAME=	wxMathPlot_0.2.0
PKGNAME=	wxmathplot-0.2.0
PKGREVISION=	16
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxmathplot/}
EXTRACT_SUFX=	.zip
WRKSRC=		${WRKDIR}/mathplot

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://wxmathplot.sourceforge.io/
COMMENT=	wxWidgets add-on for easy 2D plotting
# LGPLv2 with additional permission; http://opensource.org/licenses/wxwindows
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
