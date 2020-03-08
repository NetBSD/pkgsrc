# $NetBSD: Makefile,v 1.2 2020/03/08 16:48:12 wiz Exp $

DISTNAME=	spice-gtk-0.37
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://www.spice-space.org/download/gtk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.spice-space.org/spice-gtk.html
COMMENT=	GTK+ widget for SPICE clients
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	spice-client-glib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	spice-client-gtk-3.0.pc.in

.include "../../audio/libopus/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/spice-protocol/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
