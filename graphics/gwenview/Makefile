# $NetBSD: Makefile,v 1.8 2005/02/09 11:43:50 markd Exp $
#

DISTNAME=	gwenview-1.1.8
PKGREVISION=	1
CATEGORIES=	kde graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gwenview/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://gwenview.sourceforge.net/
COMMENT=	Image viewer for KDE whose aims are ease of use and speed

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

# Enable kipi (KDE Image Plugin Interface)
CONFIGURE_ARGS+=	--enable-kipi

SHLIBTOOL_OVERRIDE=	libtool

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
