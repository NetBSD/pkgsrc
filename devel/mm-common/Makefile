# $NetBSD: Makefile,v 1.10 2021/04/08 20:49:07 adam Exp $

DISTNAME=	mm-common-1.0.2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/mm-common/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gtkmm.org/
COMMENT=	Provides build infrastructure utilities for GNOME C++ libraries
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++
USE_TOOLS+=	gzip pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

PKGCONFIG_OVERRIDE+=	doctags/mm-common-libstdc++-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	doctags/mm-common-libstdc++.pc.in
PKGCONFIG_OVERRIDE+=	skeletonmm/skeleton/skeletonmm-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	skeletonmm/skeleton/skeletonmm.pc.in
PKGCONFIG_OVERRIDE+=	util/mm-common-util-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	util/mm-common-util.pc.in

SUBST_CLASSES+=		python3
SUBST_FILES.python3=	meson.build
SUBST_SED.python3=	-e "s,'python3','${PYTHONBIN}',"
SUBST_STAGE.python3=	pre-configure
SUBST_MESSAGE.python3=	Fix python binary name.

REPLACE_PYTHON+=	util/build_scripts/dist-build-scripts.py
REPLACE_PYTHON+=	util/build_scripts/dist-changelog.py
REPLACE_PYTHON+=	util/build_scripts/doc-reference.py
REPLACE_PYTHON+=	util/build_scripts/generate-binding.py
REPLACE_PYTHON+=	util/mm-common-get.in

.include "../../lang/python/application.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
