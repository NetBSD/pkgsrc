# $NetBSD: Makefile,v 1.10 2005/11/22 19:27:46 wiz Exp $
#

DISTNAME=		gmpc-0.12.0
CATEGORIES=		audio
MASTER_SITES=		http://download.qballcow.nl/programs/gmpc/

MAINTAINER=		pkg@burningsoda.com
HOMEPAGE=		http://qballcow.nl/?name=gmpc
COMMENT=		GNOME client for the Music Player Daemon

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

USE_DIRS+=		xdg-1.1

.include "../../audio/libmpd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
