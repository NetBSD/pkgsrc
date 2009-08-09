# $NetBSD: Makefile,v 1.19 2009/08/09 08:00:46 plunky Exp $
#

DISTNAME=	openobex-1.5
CATEGORIES=	comms
MASTER_SITES=	http://www.kernel.org/pub/linux/bluetooth/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openobex.org/
COMMENT=	Implementation of the Object Exchange (OBEX) protocol

LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	openobex.pc.in

post-patch:
	cd ${WRKSRC} && autoconf

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
