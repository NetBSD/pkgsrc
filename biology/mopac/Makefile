# $NetBSD: Makefile,v 1.19 2026/06/28 15:41:09 wiz Exp $

DISTNAME=	mopac-22.0.6
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=openmopac/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://openmopac.net/
COMMENT=	Semi-empirical (MNDO, etc.) molecular orbital calculation
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c fortran

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../mk/blas.buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
