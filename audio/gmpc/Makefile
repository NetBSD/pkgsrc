# $NetBSD: Makefile,v 1.18 2006/06/19 21:45:54 joerg Exp $
#

DISTNAME=		gmpc-0.13.0
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://download.qballcow.nl/programs/gmpc-0.13/

MAINTAINER=		pkg@burningsoda.com
HOMEPAGE=		http://qballcow.nl/?name=gmpc
COMMENT=		GNOME client for the Music Player Daemon

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config msgfmt
PKGCONFIG_OVERRIDE=	data/gmpc.pc.in

USE_DIRS+=		xdg-1.1

.include "../../audio/libmpd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
