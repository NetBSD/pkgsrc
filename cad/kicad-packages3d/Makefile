# $NetBSD: Makefile,v 1.17 2024/08/06 00:54:16 tnn Exp $

DISTNAME=	kicad-packages3D-8.0.4
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

USE_CMAKE=	yes
USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
