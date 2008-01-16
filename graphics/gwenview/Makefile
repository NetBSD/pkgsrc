# $NetBSD: Makefile,v 1.29 2008/01/16 07:54:31 wiz Exp $
#

DISTNAME=	gwenview-1.4.1
PKGREVISION=	6
CATEGORIES=	kde graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gwenview/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://gwenview.sourceforge.net/
COMMENT=	Image viewer for KDE whose aims are ease of use and speed

USE_TOOLS+=	gmake pkg-config msgfmt
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

# Enable kipi (KDE Image Plugin Interface)
CONFIGURE_ARGS+=	--enable-kipi

SHLIBTOOL_OVERRIDE=	# empty

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
