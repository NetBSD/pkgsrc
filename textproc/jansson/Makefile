# $NetBSD: Makefile,v 1.14 2026/01/25 23:05:24 wiz Exp $

DISTNAME=	jansson-2.15.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=akheron/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/akheron/jansson
COMMENT=	C library for encoding, decoding and manipulating JSON data
LICENSE=	mit

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	jansson.pc.in
# Fails a self-test because the library exports more symbols than it should.
# It seems "libtool ... -export-symbols-regex '^json_' ..." doesn't work,
# at least not on NetBSD-11.99.4/amd64.
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
