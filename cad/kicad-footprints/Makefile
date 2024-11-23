# $NetBSD: Makefile,v 1.19 2024/11/23 09:42:38 mef Exp $

DISTNAME=	kicad-footprints-8.0.6
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITLAB:=kicad/libraries/}
GITLAB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kicad.org/
COMMENT=	Component footprints for the PCB CAD software
LICENSE=	cc-by-sa-v4.0

USE_LANGUAGES=	# none

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
