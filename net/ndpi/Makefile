# $NetBSD: Makefile,v 1.1 2016/04/08 16:51:23 adam Exp $

DISTNAME=	ntopng-2.2
PKGNAME=	ndpi-1.7.1
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

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../net/libpcap/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
