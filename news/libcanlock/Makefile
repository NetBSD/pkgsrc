# $NetBSD: Makefile,v 1.5 2020/05/19 16:00:13 micha Exp $

DISTNAME=	libcanlock-3.2.0
CATEGORIES=	news
MASTER_SITES=	http://micha.freeshell.org/libcanlock/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	http://micha.freeshell.org/libcanlock/
COMMENT=	Standalone RFC 8315 Netnews Cancel-Lock implementation
LICENSE=	mit AND modified-bsd

USE_LANGUAGES+=	c99

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

TEST_TARGET=	test

# Recent NetBSD has a namespace clash with its implementation defined extensions
CFLAGS+=	-D_POSIX_C_SOURCE=200112L

CONFIGURE_ARGS+=	--disable-legacy-api
CONFIGURE_ARGS+=	--enable-pc-files
CONFIGURE_ARGS+=	--with-pkgconfigdir=${PREFIX}/lib/pkgconfig
# The header parsers are available as a separate package news/canlock-hp
CONFIGURE_ARGS+=	--disable-hp

.include "../../mk/bsd.pkg.mk"
