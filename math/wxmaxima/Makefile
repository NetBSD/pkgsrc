# $NetBSD: Makefile,v 1.1 2014/10/01 11:09:55 wiz Exp $

DISTNAME=	wxmaxima-14.09.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxmaxima/}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://andrejv.github.io/wxmaxima/
COMMENT=	Graphical UI for maxima
LICENSE=	gnu-gpl-v2

DEPENDS+=	maxima>=5.15.0:../../math/maxima
DEPENDS+=	gnuplot>=4.2.3:../../graphics/gnuplot

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

CONFLICTS+=		wxMaxima-[0-9]*

.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
