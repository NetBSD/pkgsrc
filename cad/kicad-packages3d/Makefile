# $NetBSD: Makefile,v 1.18 2024/11/20 01:22:44 mef Exp $

DISTNAME=	kicad-packages3D-8.0.6
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITLAB:=kicad/libraries/}
GITLAB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kicad.org/
COMMENT=	3D models for rendering and the MCAD software
LICENSE=	cc-by-sa-v4.0

UNLIMIT_RESOURCES=	cputime

USE_LANGUAGES=	# none

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
