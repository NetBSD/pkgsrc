# $NetBSD: Makefile,v 1.2 2014/02/12 23:18:41 tron Exp $

DISTNAME=	jansson-2.4
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.digip.org/jansson/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.digip.org/jansson/
COMMENT=	C library for encoding, decoding and manipulating JSON data
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	jansson.pc.in
# Fails a self-test because the library exports more symbols than it should.
# It seems "libtool ... -export-symbols-regex '^json_' ..." doesn't work,
# at least not on NetBSD-6.99.20/amd64.
#TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
