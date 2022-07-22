# $NetBSD: Makefile,v 1.23 2022/07/22 08:34:45 adam Exp $

DISTNAME=	gperftools-2.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=gperftools/}
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/gperftools/gperftools
COMMENT=	Fast, multi-threaded malloc() and nifty performance analysis tools
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		yes
# on some platforms heap checker is not build by default
CONFIGURE_ARGS+=	--enable-heap-checker
TEST_TARGET=		check

# for backtrace()
.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD") && exists(/usr/include/execinfo.h)
LIBS+=			-lexecinfo
CONFIGURE_ARGS+=	--enable-stacktrace-via-backtrace
.endif

PKGCONFIG_OVERRIDE=		libprofiler.pc
PKGCONFIG_OVERRIDE+=		libtcmalloc.pc
PKGCONFIG_OVERRIDE+=		libtcmalloc_debug.pc
PKGCONFIG_OVERRIDE+=		libtcmalloc_minimal.pc
PKGCONFIG_OVERRIDE+=		libtcmalloc_minimal_debug.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

REPLACE_PERL=		src/pprof

.include "../../mk/bsd.pkg.mk"
