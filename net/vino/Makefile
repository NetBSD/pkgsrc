# $NetBSD: Makefile,v 1.11 2006/01/20 16:15:53 jmmv Exp $

DISTNAME=	vino-2.12.0
PKGREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vino/2.12/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	VNC server for GNOME

USE_DIRS+=		gnome2-1.5
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl pkg-config
GNU_CONFIGURE=		yes

GCONF2_SCHEMAS=		vino-server.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
