# $NetBSD: Makefile,v 1.5 2005/05/04 17:00:06 drochner Exp $
#

DISTNAME=	showimg-0.9.4-1
PKGNAME=	showimg-0.9.4.1
CATEGORIES=	kde graphics x11
MASTER_SITES=	http://www.jalix.org/projects/showimg/download/0.9.4-1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://www.jalix.org/projects/showimg/
COMMENT=	Feature-rich image viewer for KDE including an image management system

USE_GNU_TOOLS+=	make
USE_LANGUAGE=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libkexif/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
