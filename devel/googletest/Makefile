# $NetBSD: Makefile,v 1.14 2017/07/04 20:51:07 kamil Exp $

DISTNAME=	googletest-1.8.0
PKGREVISION=	1
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

post-install:
	${RUN} cd ${DESTDIR} && find . -name '*.orig' -exec rm -f {} \;

.include "../../mk/bsd.pkg.mk"
