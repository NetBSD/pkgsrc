# $NetBSD: Makefile,v 1.12 2016/10/31 16:43:17 wiz Exp $

DISTNAME=	googletest-1.8.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://github.com/google/googletest
COMMENT=	Google's C++ testing framework
LICENSE=	modified-bsd

INSTALLATION_DIRS=	bin

USE_CMAKE=	yes
USE_LANGUAGES=	c++ c
CXXFLAGS+=	-std=c++11

.include "../../mk/bsd.pkg.mk"
