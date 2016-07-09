# $NetBSD: Makefile,v 1.5 2016/07/09 06:38:08 wiz Exp $

DISTNAME=	gperftools-2.4
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://googledrive.com/host/0B6NtGsLhIcf7MWxMMF9JdTN3UVk/

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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/heap_checker.html ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/heap_checker.html
.endif

# http://code.google.com/p/gperftools/issues/detail?id=609

PKGCONFIG_OVERRIDE=	libprofiler.pc
PKGCONFIG_OVERRIDE+=	libtcmalloc.pc
PKGCONFIG_OVERRIDE+=	libtcmalloc_debug.pc
PKGCONFIG_OVERRIDE+=	libtcmalloc_minimal.pc
PKGCONFIG_OVERRIDE+=	libtcmalloc_minimal_debug.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
