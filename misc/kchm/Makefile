# $NetBSD: Makefile,v 1.40 2014/02/12 23:18:13 tron Exp $
#

DISTNAME=	kchm-0.6.5
PKGREVISION=	33
CATEGORIES=	kde misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kchmnew/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://kchmnew.sourceforge.net/
COMMENT=	KDE CHM file viewer

GNU_CONFIGURE=	YES
SET_LIBDIR=	YES
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake

CONFLICTS=	chmlib-[0-9]*

BUILDLINK_TRANSFORM+=	rm:-fno-exceptions

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
