# $NetBSD: Makefile,v 1.38 2024/12/27 08:19:29 wiz Exp $

DISTNAME=	sratom-0.6.16
PKGREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	https://download.drobilla.net/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://drobilla.net/software/sratom.html
COMMENT=	Library for serialising LV2 atoms to/from RDF
LICENSE=	isc

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c
USE_TOOLS+=		gsed pkg-config

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/sratom-0.pc

SUBST_CLASSES+=		sphinx
SUBST_STAGE.sphinx=	pre-configure
SUBST_FILES.sphinx=	doc/meson.build
SUBST_MESSAGE.sphinx=	Fixing Python binary names.
SUBST_SED.sphinx+=	-e "s,'sphinx-build','sphinx-build-${PYVERSSUFFIX}',"
SUBST_SED.sphinx+=	-e "s,'sphinxygen','sphinxygen-${PYVERSSUFFIX}',"

.include "options.mk"

.include "../../audio/lv2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
BUILDLINK_API_DEPENDS.serd+=	serd>=0.30.0
.include "../../textproc/serd/buildlink3.mk"
BUILDLINK_API_DEPENDS.sord+=	sord>=0.14.0
.include "../../textproc/sord/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
