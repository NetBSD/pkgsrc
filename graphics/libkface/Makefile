# $NetBSD: Makefile,v 1.4.2.1 2012/10/03 12:08:09 spz Exp $
#

PKGNAME=	libkface-2.5.0
DISTNAME=	digikam-2.5.0
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.digikam.org/
COMMENT=	LibFace Library interface for KDE
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	libkface.pc.cmake

WRKSRC=			${WRKDIR}/${DISTNAME}/extra/libkface

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../graphics/opencv/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
