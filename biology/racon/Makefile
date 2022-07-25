# $NetBSD: Makefile,v 1.2 2022/07/25 11:12:20 wiz Exp $

GITHUB_PROJECT=	racon
DISTNAME=	racon-v1.4.3
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=isovic/}
GITHUB_RELEASE=	1.4.3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/isovic/racon/
COMMENT=	Genomic consensus builder
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	vendor/bioparser/vendor/zlib/contrib/minizip/minizip.pc.in
PKGCONFIG_OVERRIDE+=	vendor/bioparser/vendor/zlib/zlib.pc.in
PKGCONFIG_OVERRIDE+=	vendor/googletest/googlemock/cmake/gmock.pc.in
PKGCONFIG_OVERRIDE+=	vendor/googletest/googlemock/cmake/gmock_main.pc.in
PKGCONFIG_OVERRIDE+=	vendor/googletest/googletest/cmake/gtest.pc.in
PKGCONFIG_OVERRIDE+=	vendor/googletest/googletest/cmake/gtest_main.pc.in
PKGCONFIG_OVERRIDE+=	vendor/spoa/spoa.pc.in

INSTALLATION_DIRS+=	share/doc/racon

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/racon

.include "../../mk/bsd.pkg.mk"
