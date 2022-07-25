# $NetBSD: Makefile,v 1.10 2022/07/25 11:12:29 wiz Exp $

DISTNAME=	jansson-2.13.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.digip.org/jansson/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.digip.org/jansson/
COMMENT=	C library for encoding, decoding and manipulating JSON data
LICENSE=	mit

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	jansson.pc.in
# Fails a self-test because the library exports more symbols than it should.
# It seems "libtool ... -export-symbols-regex '^json_' ..." doesn't work,
# at least not on NetBSD-6.99.20/amd64.
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
