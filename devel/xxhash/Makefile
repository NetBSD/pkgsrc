# $NetBSD: Makefile,v 1.5 2020/07/29 13:48:32 adam Exp $

DISTNAME=	xxhash-0.8.0
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
MAKE_ENV+=		INSTALL=${TOOLS_PLATFORM.install:Q}
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_ENV+=		PKGCONFIGDIR=${PREFIX}/lib/pkgconfig
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
