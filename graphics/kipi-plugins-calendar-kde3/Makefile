# $NetBSD: Makefile,v 1.24 2012/12/16 01:52:16 obache Exp $

DISTNAME=	kipi-plugins-0.1.7
PKGNAME=	kipi-plugins-calendar-0.1.7
PKGREVISION=	23
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kipi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kipi-plugins.org/drupal/
COMMENT=	Kipi calendar plugin (KDE3)

CONFLICTS+=	kipi-plugins<0.1.4nb7

PATCHDIR=	${.CURDIR}/../../graphics/kipi-plugins-kde3/patches
DISTINFO_FILE=	${.CURDIR}/../../graphics/kipi-plugins-kde3/distinfo

USE_TOOLS+=		gmake perl pkg-config msgfmt bash:run
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	# empty

REPLACE_BASH=		kipi-plugins/mpegencoder/images2mpg

BUILD_DIRS=	kipi-plugins/calendar
INSTALL_DIRS=	kipi-plugins/calendar

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../audio/libgpod/buildlink3.mk"
.include "../../graphics/libkipi-kde3/buildlink3.mk"
.include "../../graphics/kipi-plugins-kde3/buildlink3.mk"
.include "../../graphics/libkexiv2-kde3/buildlink3.mk"
.include "../../graphics/libkdcraw-kde3/buildlink3.mk"
.include "../../misc/kdepim3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
