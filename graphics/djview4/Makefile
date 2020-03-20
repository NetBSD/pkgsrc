# $NetBSD: Makefile,v 1.45 2020/03/20 11:57:47 nia Exp $
#

DISTNAME=	djview-4.10.6
PKGNAME=	${DISTNAME:S/djview/djview4/}
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=djvu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://djvu.sourceforge.net/
COMMENT=	Portable DjVu viewer and browser plugin
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

SUBST_CLASSES+=		nsdejavu
SUBST_STAGE.nsdejavu=	pre-configure
SUBST_MESSAGE.nsdejavu=	Fixing hardcoded paths.
SUBST_FILES.nsdejavu=	nsdejavu/nsdejavu.c
SUBST_SED.nsdejavu=	-e 's:/usr/local/lib:${LOCALBASE}/lib:'

.include "../../graphics/djvulibre-lib/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
