# $NetBSD: Makefile,v 1.1.1.1 2005/01/09 10:37:57 seb Exp $

DISTNAME=	libkipi-0.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/unstable/apps/KDE3.x/graphics/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	seb@NetBSD.ORG
HOMEPAGE=	http://extragear.kde.org/apps/kipi.php
COMMENT=	KDE Image Plugin Interface

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	libtool

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
