# $NetBSD: Makefile,v 1.40 2013/02/06 23:21:18 jperkin Exp $

DISTNAME=	libkexif-0.2.5
PKGREVISION=	20
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kipi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kipi-plugins.org/drupal/
COMMENT=	Image EXIF information library manipulation

USE_TOOLS+=		gmake pkg-config msgfmt
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
SET_LIBDIR=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	# empty

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
