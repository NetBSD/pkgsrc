# $NetBSD: Makefile,v 1.11 2022/01/08 09:48:16 fox Exp $

DISTNAME=	wolfssl-5.1.1
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

PKGCONFIG_OVERRIDE+=	support/wolfssl.pc.in

USE_LIBTOOL=	yes

# XXX: Mutex related test fails with error -9906 in NetBSD 7/8/9 but
# this has been fixed in -current, libpthread in 9.99.46 
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
