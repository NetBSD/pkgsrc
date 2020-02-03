# $NetBSD: Makefile,v 1.1 2020/02/03 23:04:09 fox Exp $

DISTNAME=	wolfssl-4.3.0
CATEGORIES=	security
MASTER_SITES=	https://www.wolfssl.com/
EXTRACT_SUFX=	.zip

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://www.wolfssl.com/
COMMENT=	Embedded SSL C-Library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-dependency-tracking
CONFIGURE_ARGS+=	--enable-dh
CONFIGURE_ARGS+=	--enable-dsa
CONFIGURE_ARGS+=	--enable-dtls
CONFIGURE_ARGS+=	--enable-ecc
CONFIGURE_ARGS+=	--enable-ipv6
CONFIGURE_ARGS+=	--enable-keygen
CONFIGURE_ARGS+=	--enable-opensslextra
CONFIGURE_ARGS+=	--enable-ripemd
CONFIGURE_ARGS+=	--enable-sha512
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-sni
CONFIGURE_ARGS+=	--enable-ssh
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	--enable-tls13
CONFIGURE_ARGS+=	--enable-tls13-draft18
CONFIGURE_ARGS+=	--enable-tls13-draft22
CONFIGURE_ARGS+=	--enable-tls13-draft23
CONFIGURE_ARGS+=	--enable-tls13-draft26
CONFIGURE_ARGS+=	--enable-tls13-draft28

PKGCONFIG_OVERRIDE+=	support/wolfssl.pc.in

USE_LIBTOOL=	yes

# XXX: Tests fail in NetBSD 7/8/9 but this has been fixed in -current
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
