# $NetBSD: Makefile,v 1.4 2020/07/01 16:40:15 hauke Exp $

DISTNAME=	xxhash-0.7.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cyan4973/}
GITHUB_PROJECT=	xxHash
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Cyan4973/xxHash
COMMENT=	Extremely fast non-cryptographic hash algorithm
LICENSE=	2-clause-bsd

USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=	libxxhash.pc.in
MAKE_ENV+=		INSTALL=${TOOLS_PLATFORM.install}
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_ENV+=		PKGCONFIGDIR=${PREFIX}/lib/pkgconfig
BUILD_TARGET=		all pkgconfig
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
