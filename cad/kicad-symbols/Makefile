# $NetBSD: Makefile,v 1.8 2022/05/24 11:48:31 nikita Exp $
#

V=		6.0.2
DISTNAME=	kicad-symbols-${V}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITLAB:=kicad/libraries/}
GITLAB_PROJECT=	kicad-symbols
GITLAB_RELEASE=	${V}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kicad.org/
COMMENT=	Schematic symbol libraries for the schematic CAD software
LICENSE=	cc-by-sa-v4.0

USE_CMAKE=	yes

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
