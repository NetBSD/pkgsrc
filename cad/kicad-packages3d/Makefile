# $NetBSD: Makefile,v 1.14 2023/06/06 10:23:19 bouyer Exp $

DISTNAME=	kicad-packages3D-7.0.5
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
