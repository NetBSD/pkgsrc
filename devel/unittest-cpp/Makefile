# $NetBSD: Makefile,v 1.2 2022/07/25 11:12:24 wiz Exp $

DISTNAME=	unittest-cpp-2.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=unittest-cpp/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/unittest-cpp/unittest-cpp/
COMMENT=	Lightweight unit testing framework for C++
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	UnitTest++.pc.in

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
