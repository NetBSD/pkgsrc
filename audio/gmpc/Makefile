# $NetBSD: Makefile,v 1.26 2008/05/30 17:32:28 drochner Exp $
#

DISTNAME=		gmpc-0.15.5.0
CATEGORIES=		audio
MASTER_SITES=		http://download.qballcow.nl/gmpc-0.15.5/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sarine.nl/gmpc
COMMENT=		GNOME client for the Music Player Daemon

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool msgfmt pkg-config gmake
PKGCONFIG_OVERRIDE=	data/gmpc.pc.in

USE_DIRS+=		xdg-1.1

.include "../../audio/libmpd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
