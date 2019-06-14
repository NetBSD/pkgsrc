# $NetBSD: Makefile,v 1.5 2019/06/14 15:59:33 bouyer Exp $
#

V=		5.1.2
DISTNAME=	kicad-i18n-${V}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=KiCad/}
GITHUB_TAG=	${PKGVERSION_NOREV}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kicad-pcb.org/
COMMENT=	user interface translations for the PCB CAD software
LICENSE=	gnu-gpl-v3
CMAKE_ARGS+=	-DKICAD_REPO_NAME=stable -DKICAD_BUILD_VERSION=${V}

USE_CMAKE=	yes
BUILD_DIRS=	obj
CONFIGURE_DIRS=	${BUILD_DIRS}
CMAKE_ARG_PATH=	..

pre-configure:
	cd ${WRKSRC} && mkdir ${BUILD_DIRS}

.include "../../devel/cmake/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
