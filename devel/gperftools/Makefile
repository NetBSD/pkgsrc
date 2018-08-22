# $NetBSD: Makefile,v 1.13 2018/08/22 09:43:31 wiz Exp $

DISTNAME=	gperftools-2.7
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=gperftools/}
GITHUB_PROJECT=	gperftools
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
