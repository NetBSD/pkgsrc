# $NetBSD: Makefile,v 1.7 2021/12/02 16:40:18 tnn Exp $
#

V=		5.1.10
DISTNAME=	kicad-packages3D-${V}
PKGNAME=	kicad-packages3d-${V}
CATEGORIES=	cad
MASTER_SITES=	https://gitlab.com/kicad/libraries/kicad-packages3D/-/archive/${V}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kicad.org/
COMMENT=	3D models for rendering and the MCAD software
LICENSE=	cc-by-sa-v4.0
WRKSRC=		${WRKDIR}/kicad-packages3D-${V}

UNLIMIT_RESOURCES=	cputime

USE_CMAKE=	yes

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
