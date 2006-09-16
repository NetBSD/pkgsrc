# $NetBSD: Makefile,v 1.20 2006/09/16 12:20:35 jmmv Exp $
#

DISTNAME=		gmpc-0.13.0
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		http://download.qballcow.nl/programs/gmpc-0.13/

MAINTAINER=		pkg@burningsoda.com
HOMEPAGE=		http://qballcow.nl/?name=gmpc
COMMENT=		GNOME client for the Music Player Daemon

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool msgfmt pkg-config
PKGCONFIG_OVERRIDE=	data/gmpc.pc.in

USE_DIRS+=		xdg-1.1

.include "../../audio/libmpd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
