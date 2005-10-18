# $NetBSD: Makefile,v 1.13 2005/10/18 09:44:09 seb Exp $

DISTNAME=		digikam-0.7.4
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://digikam.sourceforge.net/
COMMENT=		KDE frontend to gphoto2

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

BUILDLINK_DEPENDS.imlib2+=	imlib2>=1.2

.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/libkexif/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
