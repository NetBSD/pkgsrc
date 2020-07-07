# $NetBSD: Makefile,v 1.7 2020/07/07 09:04:55 schmonz Exp $

DISTNAME=		cpputest-4.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=cpputest/}
GITHUB_PROJECT=		cpputest
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://cpputest.github.io/
COMMENT=		Unit testing and mocking framework for C/C++
LICENSE=		modified-bsd

PKGCONFIG_OVERRIDE+=	cpputest.pc.in

USE_CMAKE=		yes
#USE_LIBTOOL=		yes
#USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

TEST_TARGET=		check tdd

INSTALLATION_DIRS=	share/CppUTest

post-install:
	${INSTALL_DATA} ${WRKSRC}/build/MakefileWorker.mk ${DESTDIR}${PREFIX}/share/CppUTest/MakefileWorker.mk

.include "../../mk/bsd.pkg.mk"
