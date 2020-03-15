# $NetBSD: Makefile,v 1.2 2020/03/15 22:19:45 tnn Exp $

DISTNAME=	abseil-20190808
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=abseil/}
GITHUB_PROJECT=	abseil-cpp
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/abseil/abseil-cpp
COMMENT=	C++ Common Libraries
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c++11

CXXFLAGS+=	-fPIC

.include "../../mk/bsd.pkg.mk"
