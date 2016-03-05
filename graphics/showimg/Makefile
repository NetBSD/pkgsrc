# $NetBSD: Makefile,v 1.60 2016/03/05 11:28:41 jperkin Exp $
#

DISTNAME=	showimg-0.9.5
PKGREVISION=	40
CATEGORIES=	kde graphics x11
MASTER_SITES=	# http://www.jalix.org/projects/showimg/download/0.9.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://www.jalix.org/projects/showimg/
COMMENT=	Feature-rich image viewer for KDE including an image management system

USE_TOOLS+=	gmake pkg-config perl:run
REPLACE_PERL+=	showimg/showimg/misc/convert2png.pl
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--without-showimgdb

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libkexif/buildlink3.mk"
.include "../../graphics/libkipi-kde3/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
