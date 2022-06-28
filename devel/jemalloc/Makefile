# $NetBSD: Makefile,v 1.21 2022/06/28 11:31:45 wiz Exp $

DISTNAME=	jemalloc-5.2.1
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jemalloc/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://jemalloc.net/
COMMENT=	General purpose malloc(3) implementation
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_LANGUAGES=		c
USE_TOOLS+=		autoconf automake aclocal gmake perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-xmalloc
CONFIGURE_ARGS+=	--with-xslroot=${PREFIX}/share/xsl/docbook/
PKGCONFIG_OVERRIDE=	jemalloc.pc.in
BUILD_MAKE_FLAGS+=	SHELL=${CONFIG_SHELL}

REPLACE_PERL=		bin/jeprof.in

BUILD_TARGET=		all dist
TEST_TARGET=		check
TEST_ENV=		LD_LIBRARY_PATH=${WRKSRC}/lib

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
