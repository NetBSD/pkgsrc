# $NetBSD: Makefile,v 1.41 2020/11/05 09:08:08 ryoon Exp $
#

DISTNAME=	gnome-mastermind-0.3.1
PKGREVISION=	35
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/gnome-mastermind/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.autistici.org/gnome-mastermind/
COMMENT=	Mastermind (the game)

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
