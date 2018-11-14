# $NetBSD: Makefile,v 1.42 2018/11/14 22:20:59 kleink Exp $
#

DISTNAME=	albumplayer-0.3.1
PKGREVISION=	27
CATEGORIES=	audio
MASTER_SITES=	http://rvb.mytanet.de/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://rvb.mytanet.de/album-player.shtml
COMMENT=	FLAC album player
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
INSTALLATION_DIRS+=	share/applications
REPLACE_SH=		ap_flac_embed

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
