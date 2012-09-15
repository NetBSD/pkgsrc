# $NetBSD: Makefile,v 1.3 2012/09/15 10:04:57 obache Exp $
#

DISTNAME=	gwenview-1.4.2
PKGREVISION=	17
CATEGORIES=	kde graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gwenview/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://gwenview.sourceforge.net/
COMMENT=	Image viewer for KDE whose aims are ease of use and speed
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake pkg-config msgfmt perl
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
SET_LIBDIR=	YES

# Enable kipi (KDE Image Plugin Interface)
CONFIGURE_ARGS+=	--enable-kipi

SHLIBTOOL_OVERRIDE=	# empty

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libkipi-kde3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
