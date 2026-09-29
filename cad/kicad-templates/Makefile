# $NetBSD: Makefile,v 1.17 2026/09/29 16:14:34 bouyer Exp $

DISTNAME=	kicad-templates-10.0.6
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITLAB:=kicad/libraries/}
GITLAB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kicad.org/
COMMENT=	Project templates for the schematic CAD software
LICENSE=	cc-by-sa-v4.0

USE_LANGUAGES=	# none

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
