# $NetBSD: Makefile,v 1.2 2009/09/03 01:29:34 joerg Exp $
#

DISTNAME=	gbemol-0.3.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gbemol/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gbemol.sourceforge.net/
COMMENT=	Graphical frontend for the Music Player Daemon (MPD)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool

.include "../../audio/id3lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
