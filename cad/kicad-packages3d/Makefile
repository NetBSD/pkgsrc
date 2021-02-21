# $NetBSD: Makefile,v 1.5 2021/02/21 18:56:36 bouyer Exp $
#

V=		5.1.9
DISTNAME=	kicad-packages3D-${V}
PKGNAME=	kicad-packages3d-${V}
CATEGORIES=	cad
MASTER_SITES=	https://gitlab.com/kicad/libraries/kicad-packages3D/-/archive/${V}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kicad-pcb.org/
COMMENT=	3D models for rendering and the MCAD software
LICENSE=	cc-by-sa-v4.0
WRKSRC=		${WRKDIR}/kicad-packages3D-${V}

UNLIMIT_RESOURCES=	cputime

USE_CMAKE=	yes

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
