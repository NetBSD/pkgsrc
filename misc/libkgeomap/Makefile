# $NetBSD: Makefile,v 1.3 2012/09/07 19:17:11 adam Exp $
#

PKGNAME=	libkgeomap-2.5.0
DISTNAME=	digikam-2.5.0
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.digikam.org/
COMMENT=	World-Map Library interface for KDE
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	libkgeomap.pc.cmake

WRKSRC=			${WRKDIR}/${DISTNAME}/extra/libkgeomap

post-patch:
	echo "FIND_PACKAGE(Msgfmt REQUIRED)" >> ${WRKSRC}/CMakeLists.txt
	echo "FIND_PACKAGE(Gettext REQUIRED)" >> ${WRKSRC}/CMakeLists.txt
	echo "ADD_SUBDIRECTORY(po)" >> ${WRKSRC}/CMakeLists.txt
	ln -s ../../po ${WRKSRC}/po
	rm ${WRKSRC}/po/*/digikam.po ${WRKSRC}/po/*/kipiplug*

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../graphics/libkexiv2/buildlink3.mk"
.include "../../misc/marble/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
