# $NetBSD: Makefile,v 1.4 2008/07/30 10:57:25 drochner Exp $
#

DISTNAME=	gimmix-0.4.3
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/gimmix/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gimmix.berlios.de/
COMMENT=	Graphical Music player daemon (MPD) client

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool msgfmt pkg-config
USE_DIRS+=	xdg-1.1

.include "../../x11/gtk2/buildlink3.mk"
.include "../../audio/libmpd/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
