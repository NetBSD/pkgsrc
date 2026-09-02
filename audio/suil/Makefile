# $NetBSD: Makefile,v 1.48 2026/09/02 19:01:01 wiz Exp $

DISTNAME=	suil-0.10.26
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	https://download.drobilla.net/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://drobilla.net/software/suil/
COMMENT=	Lightweight C library for loading and wrapping LV2 plugin UIs
LICENSE=	isc

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		sphinx
SUBST_STAGE.sphinx=	pre-configure
SUBST_FILES.sphinx=	doc/meson.build
SUBST_MESSAGE.sphinx=	Fixing Python binary names.
SUBST_SED.sphinx+=	-e "s,'sphinx-build','sphinx-build-${PYVERSSUFFIX}',"
SUBST_SED.sphinx+=	-e "s,'sphinxygen','sphinxygen-${PYVERSSUFFIX}',"

.include "options.mk"

BUILDLINK_API_DEPENDS.lv2+=	lv2>=1.18.4
.include "../../audio/lv2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
