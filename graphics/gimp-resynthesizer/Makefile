# $NetBSD: Makefile,v 1.71 2026/01/27 08:39:39 wiz Exp $

DISTNAME=	resynthesizer-3.0.0
PKGNAME=	gimp-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=bootchk/}
GITHUB_PROJECT=	resynthesizer
GITHUB_TAG=	v3.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bootchk/resynthesizer
COMMENT=	Suite of gimp plug-ins for texture synthesis
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		scm
SUBST_FILES.scm+=	outerPlugins/plug-in-heal-selection.scm
SUBST_FILES.scm+=	outerPlugins/plug-in-heal-transparency.scm
SUBST_FILES.scm+=	outerPlugins/plug-in-map-style.scm
SUBST_FILES.scm+=	outerPlugins/plug-in-render-texture.scm
SUBST_FILES.scm+=	outerPlugins/plug-in-resynth-controls.scm
SUBST_FILES.scm+=	outerPlugins/plug-in-resynth-enlarge.scm
SUBST_FILES.scm+=	outerPlugins/plug-in-resynth-fill-pattern.scm
SUBST_FILES.scm+=	outerPlugins/plug-in-resynth-sharpen.scm
SUBST_FILES.scm+=	outerPlugins/plug-in-uncrop.scm
SUBST_SED.scm+=		-e "s,\#!/usr/bin/env ,\#!${PREFIX}/bin/,"
SUBST_STAGE.scm=	pre-configure
SUBST_MESSAGE.scm=	Fixing path to gimp-script-fu-interpreter-3.0.

.include "../../devel/meson/build.mk"
.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
