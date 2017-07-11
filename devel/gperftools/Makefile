# $NetBSD: Makefile,v 1.9 2017/07/11 06:50:24 adam Exp $

DISTNAME=	gperftools-2.6.1
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
USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		yes
# on some platforms heap checker is not build by default
CONFIGURE_ARGS+=	--enable-heap-checker
# enable deprecated ucontext
CFLAGS.Darwin+=		-D_XOPEN_SOURCE=1

# for backtrace()
.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD") && exists(/usr/include/execinfo.h)
LIBS+=			-lexecinfo
.endif

PKGCONFIG_OVERRIDE=	libprofiler.pc
PKGCONFIG_OVERRIDE+=	libtcmalloc.pc
PKGCONFIG_OVERRIDE+=	libtcmalloc_debug.pc
PKGCONFIG_OVERRIDE+=	libtcmalloc_minimal.pc
PKGCONFIG_OVERRIDE+=	libtcmalloc_minimal_debug.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

REPLACE_PERL=		src/pprof

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
