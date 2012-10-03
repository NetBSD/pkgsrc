# $NetBSD: Makefile,v 1.15.2.1 2012/10/03 12:08:12 spz Exp $

DISTNAME=	qimageblitz-0.0.6
PKGREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=   ${MASTER_SITE_KDE:=qimageblitz/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/qimageblitz
COMMENT=	Interm graphical effect and filter library for KDE4.0

USE_LANGUAGES+= c c++
USE_CMAKE= yes

PKG_DESTDIR_SUPPORT=	user-destdir

#BUILD_MAKE_FLAGS+= VERBOSE=1

PKGCONFIG_OVERRIDE+=	blitz/qimageblitz.pc.cmake

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
