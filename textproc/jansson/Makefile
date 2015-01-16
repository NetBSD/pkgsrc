# $NetBSD: Makefile,v 1.5 2015/01/16 11:50:28 wiz Exp $

DISTNAME=	jansson-2.7
CATEGORIES=	textproc
MASTER_SITES=	http://www.digip.org/jansson/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.digip.org/jansson/
COMMENT=	C library for encoding, decoding and manipulating JSON data
LICENSE=	mit

USE_LANGUAGES=	c99
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	jansson.pc.in
# Fails a self-test because the library exports more symbols than it should.
# It seems "libtool ... -export-symbols-regex '^json_' ..." doesn't work,
# at least not on NetBSD-6.99.20/amd64.
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
