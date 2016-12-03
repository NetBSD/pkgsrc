# $NetBSD: Makefile,v 1.2 2016/12/03 13:02:22 sevan Exp $
#

DISTNAME=		dfu-util-0.9
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dfu-util/files/}

MAINTAINER=		noud4@users.sourceforge.net
HOMEPAGE=		http://dfu-util.sourceforge.net/
COMMENT=		Host side implementation of the USB DFU protocol
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE= 		YES

CPPFLAGS+= 		"-I${BUILDLINK_PREFIX.libusb1}/include/libusb-1.0"

CONFIGURE_ARGS+=	-prefix=${PREFIX}
CONFIGURE_ARGS+= 	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "FreeBSD" && ${OPSYS} != "DragonFly"
BUILDLINK_TRANSFORM+=	l:usb:usb-1.0
.endif

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
