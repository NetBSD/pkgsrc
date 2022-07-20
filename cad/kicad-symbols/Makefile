# $NetBSD: Makefile,v 1.9 2022/07/20 16:28:54 tnn Exp $
#

V=		6.0.6
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
