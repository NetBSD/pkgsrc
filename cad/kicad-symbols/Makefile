# $NetBSD: Makefile,v 1.17 2026/09/29 16:14:06 bouyer Exp $

DISTNAME=	kicad-symbols-10.0.6
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITLAB:=kicad/libraries/}
GITLAB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kicad.org/
COMMENT=	Schematic symbol libraries for the schematic CAD software
LICENSE=	cc-by-sa-v4.0

USE_LANGUAGES=		# none
PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/cmake/build.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
