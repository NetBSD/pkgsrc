# $NetBSD: Makefile,v 1.1.1.1 2008/01/12 14:09:35 dillo Exp $
#

DISTNAME=	libsyncml-0.4.5
CATEGORIES=	comms
MASTER_SITES=	http://libsyncml.opensync.org/download/releases/0.4.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://libsyncml.opensync.org/
COMMENT=	C library implementation of the SyncML protocol

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-http
CONFIGURE_ARGS+=	--enable-bluetooth
CONFIGURE_ARGS+=	--enable-obex

PKGCONFIG_OVERRIDE+=	libsyncml-1.0.pc.in

.include "../../comms/openobex/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/wbxml2/buildlink3.mk"
# XXX libsoup (http)
.include "../../mk/bsd.pkg.mk"
