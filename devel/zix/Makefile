# $NetBSD: Makefile,v 1.1 2024/11/05 17:08:40 adam Exp $

DISTNAME=	zix-0.4.2
CATEGORIES=	devel
MASTER_SITES=	https://download.drobilla.net/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/drobilla/zix
COMMENT=	Lightweight C library of portability wrappers and data structures
LICENSE=	isc

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/zix-0.pc

SUBST_CLASSES+=		sphinx
SUBST_STAGE.sphinx=	pre-configure
SUBST_FILES.sphinx=	doc/meson.build
SUBST_MESSAGE.sphinx=	Fixing Python binary names.
SUBST_SED.sphinx+=	-e "s,'sphinx-build','sphinx-build-${PYVERSSUFFIX}',"
SUBST_SED.sphinx+=	-e "s,'sphinxygen','sphinxygen-${PYVERSSUFFIX}',"

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
