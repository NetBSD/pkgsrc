# $NetBSD: Makefile,v 1.1 2025/08/31 19:18:18 wiz Exp $

DISTNAME=	Mustache-4.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=kainjow/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kainjow/Mustache/
COMMENT=	Text templates for modern C++
LICENSE=	boost-license

USE_LANGUAGES=	c c++

WRKSRC=		${WRKDIR}/${DISTNAME}

INSTALLATION_DIRS=	include

do-configure:

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/mustache.hpp ${DESTDIR}${PREFIX}/include

#.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
