# $NetBSD: Makefile,v 1.60 2022/07/02 16:53:22 ryoon Exp $
#

DISTNAME=	djview-4.12
PKGNAME=	${DISTNAME:S/djview/djview4/}
PKGREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=djvu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://djvu.sourceforge.net/
COMMENT=	Portable DjVu viewer and browser plugin
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	autogen.sh
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	automake gmake pkg-config

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
