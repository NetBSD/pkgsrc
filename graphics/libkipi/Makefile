# $NetBSD: Makefile,v 1.6 2005/11/02 06:56:55 wiz Exp $

DISTNAME=	libkipi-0.1.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://extragear.kde.org/apps/kipi/
COMMENT=	KDE Image Plugin Interface

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	libtool

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
