# $NetBSD: Makefile,v 1.8 2021/02/21 18:56:36 bouyer Exp $
#

V=		5.1.9
DISTNAME=	kicad-i18n-${V}
CATEGORIES=	cad
MASTER_SITES=	https://gitlab.com/kicad/code/kicad-i18n/-/archive/${V}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kicad-pcb.org/
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
