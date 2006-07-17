# $NetBSD: Makefile,v 1.7 2006/07/17 12:29:57 xtraeme Exp $
#

DISTNAME=	obexftp-0.20
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openobex/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://triq.net/obex/
COMMENT=	File copying over the Object Exchange (OBEX) protocol

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake pkg-config
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-swig

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD" && exists(/usr/include/bluetooth.h))
CPPFLAGS+=		-DCOMPAT_BLUEZ
.endif

post-patch:
	cd ${WRKSRC} && autoconf

.include "../../comms/openobex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
