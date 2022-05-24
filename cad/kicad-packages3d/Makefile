# $NetBSD: Makefile,v 1.10 2022/05/24 11:15:56 nikita Exp $
#

V=		6.0.2
DISTNAME=	kicad-packages3D-${V}
PKGNAME=	kicad-packages3d-${V}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITLAB:=kicad/libraries/}
GITLAB_PROJECT=	kicad-packages3D
GITLAB_RELEASE=	${V}
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
