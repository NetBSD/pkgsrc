# $NetBSD: Makefile,v 1.24 2007/11/18 10:23:22 wiz Exp $
#

DISTNAME=		gmpc-0.13.0
PKGREVISION=		6
CATEGORIES=		audio
MASTER_SITES=		#
# http://sarine.nl/index.php?mact=Uploads,cntnt01,getfile,0&cntnt01showtemplate=false&cntnt01upload_id=1&cntnt01returnid=71

MAINTAINER=		pkg@burningsoda.com
HOMEPAGE=		http://sarine.nl/gmpc
COMMENT=		GNOME client for the Music Player Daemon

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool msgfmt pkg-config
PKGCONFIG_OVERRIDE=	data/gmpc.pc.in

USE_DIRS+=		xdg-1.1

.include "../../audio/libmpd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
