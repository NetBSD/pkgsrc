# $NetBSD: Makefile,v 1.4 2009/09/09 16:54:13 drochner Exp $
#

DISTNAME=	albumplayer_0.3.orig
PKGNAME=	albumplayer-0.3
CATEGORIES=	audio
MASTER_SITES=	http://rvb.mytanet.de/debian/

MAINTAINER=	pkgstc-users@NetBSD.org
HOMEPAGE=	http://rvb.mytanet.de/
COMMENT=	FLAC album player
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}/${PKGNAME}

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
