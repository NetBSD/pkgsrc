# $NetBSD: Makefile,v 1.2 2014/05/29 23:35:35 wiz Exp $

DISTNAME=	gperftools-2.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://gperftools.googlecode.com/files/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://code.google.com/p/gperftools/
COMMENT=	Fast, multi-threaded malloc() and nifty performance analysis tools
LICENSE=	modified-bsd

USE_TOOLS+=		perl:run
REPLACE_PERL=		src/pprof

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--enable-frame-pointers # per README

# http://code.google.com/p/gperftools/issues/detail?id=609

PKGCONFIG_OVERRIDE=	libprofiler.pc
PKGCONFIG_OVERRIDE+=	libtcmalloc.pc
PKGCONFIG_OVERRIDE+=	libtcmalloc_debug.pc
PKGCONFIG_OVERRIDE+=	libtcmalloc_minimal.pc
PKGCONFIG_OVERRIDE+=	libtcmalloc_minimal_debug.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
