# $NetBSD: Makefile,v 1.11 2022/05/24 10:55:59 nikita Exp $
#

V=		6.0.2
DISTNAME=	kicad-footprints-${V}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITLAB:=kicad/libraries/}
GITLAB_PROJECT=	kicad-footprints
GITLAB_RELEASE=	${V}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kicad.org/
COMMENT=	Component footprints for the PCB CAD software
LICENSE=	cc-by-sa-v4.0

USE_CMAKE=	yes

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
