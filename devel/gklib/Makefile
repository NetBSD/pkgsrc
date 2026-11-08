# $NetBSD: Makefile,v 1.1 2026/11/08 13:21:40 ryoon Exp $

DISTNAME=	GKlib
PKGNAME=	gklib-0.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=KarypisLab/}
GITHUB_PROJECT=	GKlib
GITHUB_TAG=	3b7d61b9f885063c89901f3901fb4426f9cfb58f

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/KarypisLab/GKlib/
COMMENT=	Utility library of software from Karypis Lab
LICENSE=	apache-2.0

CMAKE_CONFIGURE_ARGS+=	-DSHARED=ON

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
