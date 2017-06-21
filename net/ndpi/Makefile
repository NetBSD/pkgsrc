# $NetBSD: Makefile,v 1.2.6.1 2017/06/21 18:39:02 bsiegert Exp $

DISTNAME=	ntopng-2.4-stable
PKGNAME=	ndpi-1.8.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ntop/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ntop.org/
COMMENT=	Library for deep-packet inspection
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake gmake pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libndpi.pc.in

EXTRACT_ELEMENTS=	${DISTNAME}/nDPI
WRKSRC=			${WRKDIR}/${DISTNAME}/nDPI

# Portable types
CFLAGS.SunOS+=		-Du_int8_t=uint8_t
CFLAGS.SunOS+=		-Du_int16_t=uint16_t
CFLAGS.SunOS+=		-Du_int32_t=uint32_t
CFLAGS.SunOS+=		-Du_int64_t=uint64_t

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../net/libpcap/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
