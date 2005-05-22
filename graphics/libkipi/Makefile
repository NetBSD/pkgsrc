# $NetBSD: Makefile,v 1.4 2005/05/22 20:08:06 jlam Exp $

DISTNAME=	libkipi-0.1.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/unstable/apps/KDE3.x/graphics/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	seb@NetBSD.ORG
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
