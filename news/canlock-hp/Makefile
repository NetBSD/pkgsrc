# $NetBSD: Makefile,v 1.11 2024/05/31 10:55:37 micha Exp $

DISTNAME=	libcanlock-3.3.1
PKGNAME=	${DISTNAME:S/libcanlock/canlock-hp/}
CATEGORIES=	news
MASTER_SITES=	http://micha.freeshell.org/libcanlock/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://micha.freeshell.org/libcanlock/
COMMENT=	Parsers for RFC 5536 message headers and RFC 8315 header fields
LICENSE=	icu

USE_TOOLS+=		lex yacc
FORCE_C_STD=		c99
USE_CC_FEATURES+=	c99
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-pc-files
CONFIGURE_ARGS+=	--with-pkgconfigdir=${PREFIX}/lib/pkgconfig

CONFIGURE_DIRS=	hp
BUILD_DIRS=	hp
TEST_TARGET=	test

PKGCONFIG_OVERRIDE+=	hp/libcanlock-hp-3.pc.in

.include "../../mk/bsd.pkg.mk"
