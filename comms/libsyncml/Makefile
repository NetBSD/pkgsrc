# $NetBSD: Makefile,v 1.15 2020/11/05 09:07:38 ryoon Exp $
#

DISTNAME=	libsyncml-0.4.5
PKGREVISION=	9
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libsyncml/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://libsyncml.opensync.org/
COMMENT=	C library implementation of the SyncML protocol
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c
USE_LIBTOOL=	yes

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--disable-http
.if ${OPSYS} != "SunOS"
CONFIGURE_ARGS+=	--enable-bluetooth
.endif
CONFIGURE_ARGS+=	--enable-obex

PKGCONFIG_OVERRIDE+=	libsyncml-1.0.pc.in

.include "../../comms/openobex/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/wbxml2/buildlink3.mk"
# XXX libsoup (http)
.include "../../mk/bsd.pkg.mk"
