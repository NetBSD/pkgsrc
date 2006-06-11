# $NetBSD: Makefile,v 1.12 2006/06/11 14:30:09 joerg Exp $

DISTNAME=	libkipi-0.1.2
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://extragear.kde.org/apps/kipi/
COMMENT=	KDE Image Plugin Interface

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake msgfmt
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	libtool

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
