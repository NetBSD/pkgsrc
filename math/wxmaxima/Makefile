# $NetBSD: Makefile,v 1.35 2024/05/29 16:33:29 adam Exp $

DISTNAME=	wxmaxima-23.12.0
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=wxMaxima-developers/}
GITHUB_TAG=	Version-${PKGVERSION_NOREV}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	https://github.com/wxMaxima-developers/wxmaxima/
COMMENT=	Graphical UI for maxima
LICENSE=	gnu-gpl-v2

DEPENDS+=	maxima>=5.15.0:../../math/maxima
DEPENDS+=	gnuplot>=4.2.3:../../graphics/gnuplot

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	data/CMakeLists.txt
SUBST_FILES.paths+=	locales/CMakeLists.txt
SUBST_SED.paths=	-e 's,share/locale,${PKGLOCALEDIR}/locale,g'
SUBST_SED.paths+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_NOOP_OK.paths=	yes

.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
