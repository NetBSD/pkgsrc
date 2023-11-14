# $NetBSD: Makefile,v 1.31 2023/11/14 14:02:28 wiz Exp $

DISTNAME=	wxmaxima-17.10.1
PKGREVISION=	23
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=andrejv/}
GITHUB_TAG=	Version-${PKGVERSION_NOREV}

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	https://andrejv.github.io/wxmaxima/
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

.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
