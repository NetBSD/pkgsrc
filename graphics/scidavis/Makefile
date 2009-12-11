# $NetBSD: Makefile,v 1.1.1.1 2009/12/11 20:13:49 drochner Exp $
#

DISTNAME=	scidavis-0.2.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scidavis/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scidavis.sourceforge.net/
COMMENT=	Data analysis and visualization package

USE_LANGUAGES=	c c++
PKG_DESTDIR_SUPPORT= user-destdir
INSTALL_MAKE_FLAGS+= INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${QTDIR}/bin/qmake

# XXX patched out for now
#.include "../../lang/python/extension.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../math/muparser/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../x11/qwt-qt4/buildlink3.mk"
.include "../../x11/qwtplot3d-qt4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
