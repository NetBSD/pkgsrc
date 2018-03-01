# $NetBSD: Makefile,v 1.4 2018/03/01 13:59:11 mef Exp $
#

V=		4.0.7
DISTNAME=	kicad-library-${V}
PKGNAME=	kicad-lib-${V}
CATEGORIES=	cad
MASTER_SITES=	http://downloads.kicad-pcb.org/libraries/
EXTRACT_USING=	bsdtar

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://kicad-pcb.org/
COMMENT=	Libraries for the schematic CAD software
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_CMAKE=		yes
CMAKE_ARGS+=		-DKICAD_REPO_NAME=stable -DKICAD_BUILD_VERSION=${V}

.include "../../devel/cmake/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
