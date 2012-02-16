# $NetBSD: Makefile,v 1.14 2012/02/16 17:40:29 hans Exp $
#

DISTNAME=	obexftp-0.20
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openobex/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openobex.triq.net/
COMMENT=	File copying over the Object Exchange (OBEX) protocol

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake pkg-config
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-swig

LIBS.SunOS+=		-lsocket -lnsl -liconv

.include "../../mk/bsd.prefs.mk"

.if ((${OPSYS} == "NetBSD" && exists(/usr/include/bluetooth.h)) || ${OPSYS} == "DragonFly")
CPPFLAGS+=		-DCOMPAT_BLUEZ -DSDP_COMPAT
.endif

post-patch:
	cd ${WRKSRC} && autoconf

.include "../../comms/openobex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
