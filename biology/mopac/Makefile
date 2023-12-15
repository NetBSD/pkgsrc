# $NetBSD: Makefile,v 1.14 2023/12/15 13:50:36 wiz Exp $

DISTNAME=	mopac-22.0.6
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=openmopac/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openmopac.net/
COMMENT=	Semi-empirical (MNDO, etc.) molecular orbital calculation
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c fortran

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../mk/blas.buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
