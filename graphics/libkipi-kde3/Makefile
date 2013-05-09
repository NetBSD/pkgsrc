# $NetBSD: Makefile,v 1.9 2013/05/09 07:39:11 adam Exp $

DISTNAME=	libkipi-0.1.6
PKGREVISION=	19
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kipi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kipi-plugins.org/drupal/
COMMENT=	KDE Image Plugin Interface

USE_TOOLS+=		gmake msgfmt
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
SET_LIBDIR=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	# empty

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
