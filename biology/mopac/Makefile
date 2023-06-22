# $NetBSD: Makefile,v 1.10 2023/06/22 12:08:24 bacon Exp $

DISTNAME=	mopac-22.0.6
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=openmopac/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

OWNER=		pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openmopac.net/
COMMENT=	Semi-empirical (MNDO, etc.) molecular orbital calculation
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c fortran

.include "../../mk/blas.buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
