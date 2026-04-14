# $NetBSD: Makefile,v 1.27 2026/04/14 12:49:12 adam Exp $

DISTNAME=	jemalloc-5.3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jemalloc/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://jemalloc.net/
COMMENT=	General purpose malloc(3) implementation
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c
USE_TOOLS+=		autoconf automake aclocal gmake perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-xmalloc
CONFIGURE_ARGS+=	--with-xslroot=${PREFIX}/share/xsl/docbook/
PKGCONFIG_OVERRIDE=	jemalloc.pc.in
BUILD_MAKE_FLAGS+=	SHELL=${CONFIG_SHELL:Q}

REPLACE_PERL=		bin/jeprof.in

BUILD_TARGET=		all
TEST_TARGET=		check
TEST_ENV=		LD_LIBRARY_PATH=${WRKSRC}/lib

PRINT_PLIST_AWK+=	{ if (/^share\/doc/) $$0 = "$${PLIST.doc}" $$0 }

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
