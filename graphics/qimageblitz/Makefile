# $NetBSD: Makefile,v 1.4 2010/06/13 22:44:43 wiz Exp $

DISTNAME=	qimageblitz-0.0.4
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=qimageblitz/}
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
