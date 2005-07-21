# $NetBSD: Makefile,v 1.4 2005/07/21 16:29:51 wiz Exp $

DISTNAME=	libkexif-0.2.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	seb@NetBSD.ORG
HOMEPAGE=	http://digikam.sourceforge.net/
COMMENT=	Image EXIF information library manipulation

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	libtool

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
