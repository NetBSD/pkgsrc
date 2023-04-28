# $NetBSD: Makefile,v 1.11 2023/04/28 18:13:52 nikita Exp $

DISTNAME=	jansson-2.14
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=akheron/}
GITHUB_PROJECT=	jansson
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

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
