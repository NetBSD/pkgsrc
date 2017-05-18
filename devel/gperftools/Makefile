# $NetBSD: Makefile,v 1.7 2017/05/18 18:12:30 adam Exp $

DISTNAME=	gperftools-2.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=gperftools/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/gperftools/gperftools
COMMENT=	Fast, multi-threaded malloc() and nifty performance analysis tools
LICENSE=	modified-bsd

GITHUB_PROJECT=	gperftools
GITHUB_RELEASE=	${DISTNAME}

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
# on some platforms heap checker is not build by default
CONFIGURE_ARGS+=	--enable-heap-checker

PKGCONFIG_OVERRIDE=	libprofiler.pc
PKGCONFIG_OVERRIDE+=	libtcmalloc.pc
PKGCONFIG_OVERRIDE+=	libtcmalloc_debug.pc
PKGCONFIG_OVERRIDE+=	libtcmalloc_minimal.pc
PKGCONFIG_OVERRIDE+=	libtcmalloc_minimal_debug.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

REPLACE_PERL=		src/pprof

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
