# $NetBSD: Makefile,v 1.9 2023/08/30 13:16:32 micha Exp $

DISTNAME=	libcanlock-3.3.0
PKGNAME=	${DISTNAME:S/libcanlock/canlock-hp/}
PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://micha.freeshell.org/libcanlock/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://micha.freeshell.org/libcanlock/
COMMENT=	Parsers for RFC 5536 message headers and RFC 8315 header fields
LICENSE=	mit

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

.include "../../mk/bsd.pkg.mk"
