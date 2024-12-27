# $NetBSD: Makefile,v 1.48 2024/12/27 08:19:21 wiz Exp $

DISTNAME=	lilv-0.24.24
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://download.drobilla.net/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://drobilla.net/software/lilv.html
COMMENT=	C library to make the use of LV2 plugins as simple as possible
LICENSE=	isc

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_TOOLS+=		gsed pkg-config
FORCE_CXX_STD=		c++11

MESON_ARGS+=	-Dbindings_py=disabled

CPPFLAGS.SunOS+=	-D__EXTENSIONS__

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/lilv-0.pc

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		sphinx
SUBST_STAGE.sphinx=	pre-configure
SUBST_FILES.sphinx=	doc/meson.build
SUBST_MESSAGE.sphinx=	Fixing Python binary names.
SUBST_SED.sphinx+=	-e "s,'sphinx-build','sphinx-build-${PYVERSSUFFIX}',"
SUBST_SED.sphinx+=	-e "s,'sphinxygen','sphinxygen-${PYVERSSUFFIX}',"

.include "options.mk"

BUILDLINK_API_DEPENDS.lv2+=	lv2>=1.18.0
.include "../../audio/lv2/buildlink3.mk"
.include "../../converters/sratom/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
BUILDLINK_API_DEPENDS.serd+=	serd>=0.30.10
.include "../../textproc/serd/buildlink3.mk"
BUILDLINK_API_DEPENDS.sord+=	sord>=0.16.15
.include "../../textproc/sord/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
