# $NetBSD: Makefile,v 1.13 2017/05/03 08:38:40 jperkin Exp $

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
USE_LANGUAGES=	c c++11

.include "../../mk/bsd.pkg.mk"
