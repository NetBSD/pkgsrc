# $NetBSD: Makefile,v 1.1 2021/05/04 14:12:05 prlw1 Exp $

PKGNAME=	libharu-2.4.0
DISTNAME=	libharu-2.3.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=libharu/}
GITHUB_TAG=	RELEASE_2_3_0
DIST_SUBDIR=	libharu

# Kitware (vtk) calls this version 2.4.0 with the addition of
PATCHFILES=	157.diff 187.diff
PATCH_SITES=	${MASTER_SITE_GITHUB:=libharu/}libharu/pull/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://github.com/libharu/libharu/
COMMENT=	Software library for generating PDF
LICENSE=	zlib

USE_CMAKE=	yes
USE_LANGUAGES=	c c++


CMAKE_ARGS+=	-DLIBHPDF_STATIC=OFF

PATCH_DIST_STRIP=	-p1
SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-configure
SUBST_MESSAGE.version=	Change version to 2.4.0
SUBST_FILES.version=	include/hpdf_version.h
SUBST_SED.version=	-e 's/3/4/'
SUBST_SED.version+=	-e 's/RC2/dev/'

INSTALLATION_DIRS=	include lib
do-install:
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/libhpdf.so ${DESTDIR}${PREFIX}/lib

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
