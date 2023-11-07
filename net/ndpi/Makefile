# $NetBSD: Makefile,v 1.12 2023/11/07 22:31:11 he Exp $

DISTNAME=	nDPI-4.6
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ntop/}
GITHUB_PROJECT=	nDPI

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://www.ntop.org/
COMMENT=	Library for deep-packet inspection
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake gmake pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libndpi.pc.in
MAKE_ENV+=		OS=${OPSYS}
TEST_TARGET=		check

# Portable types
CFLAGS.SunOS+=		-Du_int8_t=uint8_t
CFLAGS.SunOS+=		-Du_int16_t=uint16_t
CFLAGS.SunOS+=		-Du_int32_t=uint32_t
CFLAGS.SunOS+=		-Du_int64_t=uint64_t

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../net/libpcap/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
