# $NetBSD: Makefile,v 1.16 2020/06/02 08:24:17 adam Exp $

DISTNAME=	wxmaxima-17.10.1
PKGREVISION=	9
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=andrejv/}
GITHUB_TAG=	Version-${PKGVERSION_NOREV}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	https://andrejv.github.io/wxmaxima/
COMMENT=	Graphical UI for maxima
LICENSE=	gnu-gpl-v2

DEPENDS+=	maxima>=5.15.0:../../math/maxima
DEPENDS+=	gnuplot>=4.2.3:../../graphics/gnuplot

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
