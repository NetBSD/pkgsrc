# $NetBSD: Makefile,v 1.1 2024/05/04 18:06:23 schmonz Exp $

DISTNAME=		aceunit-${GITHUB_TAG}
PKGNAME=		${DISTNAME:S/-v/-/}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=christianhujer/}
GITHUB_TAG=		v3.0.0

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://nelkinda.com/products/aceunit/
COMMENT=		Advanced C and Embedded Unit test framework
LICENSE=		modified-bsd

USE_TOOLS+=		bash:run gmake
FORCE_C_STD=		c90
TOOLS_PLATFORM.bash=	# undef, to avoid too-old vendor bash
REPLACE_BASH=		bin/aceunit
BUILD_TARGET=		build	# need to build the tests in this phase
MAKE_ENV+=		MANDIR=${PKGMANDIR:Q}
TEST_TARGET=		test-all

post-extract:
	[ ${PKGMANDIR} = "share/man" ] || ${MV} -f ${WRKSRC}/share/man ${WRKSRC}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
