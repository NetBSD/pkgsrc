# $NetBSD: Makefile,v 1.2 2009/08/03 09:55:36 drochner Exp $
#

DISTNAME=	albumplayer-0.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://rvb.mytanet.de/
# XXX distfile was modified after release
DIST_SUBDIR=	albumplayer_modified_0.2

MAINTAINER=	pkgstc-users@NetBSD.org
HOMEPAGE=	http://rvb.mytanet.de/
COMMENT=	FLAC album player
LICENSE=	original-bsd

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
USE_DIRS+=		xdg-1.1
PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	share/applications

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
