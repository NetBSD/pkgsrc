# $NetBSD: Makefile,v 1.8 2024/05/29 16:33:28 adam Exp $

DISTNAME=	wxMathPlot_0.2.0
PKGNAME=	wxmathplot-0.2.0
PKGREVISION=	7
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxmathplot/}
EXTRACT_SUFX=	.zip
WRKSRC=		${WRKDIR}/mathplot


MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	https://wxmathplot.sourceforge.io/
COMMENT=	wxWidgets add-on for easy 2D plotting
# LGPLv2 with additional permission; http://opensource.org/licenses/wxwindows
LICENSE=	gnu-lgpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
