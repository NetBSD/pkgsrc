# $NetBSD: Makefile,v 1.12 2024/05/31 10:47:15 micha Exp $

DISTNAME=	libcanlock-3.3.1
CATEGORIES=	news
MASTER_SITES=	http://micha.freeshell.org/libcanlock/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://micha.freeshell.org/libcanlock/
COMMENT=	Standalone RFC 8315 Netnews Cancel-Lock implementation
LICENSE=	icu AND modified-bsd

FORCE_C_STD=		c99
USE_CC_FEATURES+=	c99
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-legacy-api
CONFIGURE_ARGS+=	--enable-pc-files
CONFIGURE_ARGS+=	--with-pkgconfigdir=${PREFIX}/lib/pkgconfig
# The header parsers are available as a separate package news/canlock-hp
CONFIGURE_ARGS+=	--disable-hp

TEST_TARGET=		test

PKGCONFIG_OVERRIDE+=	libcanlock-3.pc.in

.include "../../mk/bsd.pkg.mk"
