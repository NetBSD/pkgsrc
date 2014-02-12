# $NetBSD: Makefile,v 1.40 2014/02/12 23:18:02 tron Exp $
#

DISTNAME=	kphotobook-0.0.6
PKGREVISION=	34
CATEGORIES=	kde graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kphotobook/}

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://kphotobook.berlios.de/
COMMENT=	Powerful, intuitive KDE application to manage and organize your photos

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
