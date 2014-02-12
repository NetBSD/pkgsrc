# $NetBSD: Makefile,v 1.28 2014/02/12 23:18:03 tron Exp $
#

DISTNAME=	scidavis-0.2.4
PKGREVISION=	20
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scidavis/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scidavis.sourceforge.net/
COMMENT=	Data analysis and visualization package

USE_LANGUAGES=	c c++
INSTALL_MAKE_FLAGS+= INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake

BUILDLINK_DEPMETHOD.qt4-tools=	full

# XXX patched out for now
#.include "../../lang/python/extension.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../math/muparser/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
BUILDLINK_API_DEPENDS.qwt+= qwt<6
.include "../../x11/qwt-qt4/buildlink3.mk"
.include "../../x11/qwtplot3d-qt4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
