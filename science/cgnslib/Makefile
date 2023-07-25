# $NetBSD: Makefile,v 1.1 2023/07/25 11:23:54 thor Exp $

PKGNAME=	cgnslib-4.4.0
GITHUB_PROJECT=	CGNS
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_GITHUB:=CGNS/}

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://cgns.github.io/
COMMENT=	CFD General Notation System
LICENSE=	zlib

USE_LANGUAGES=	c fortran

# cmake seems preferred
CHECK_PORTABILITY_SKIP+=	src/configure

.include "../../devel/cmake/build.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
