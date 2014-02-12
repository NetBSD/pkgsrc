# $NetBSD: Makefile,v 1.46 2014/02/12 23:18:02 tron Exp $
#

DISTNAME=	kphotools-0.2.1
PKGREVISION=	38
CATEGORIES=	kde graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kphotools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://kphotools.sourceforge.net/
COMMENT=	KDE app which helps you creating fast online photo galleries in HTML

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

SUBST_CLASSES+=		kphotools
SUBST_MESSAGE.kphotools=	Fixing /usr/share path.
SUBST_FILES.kphotools=	src/GalleryThrd.cpp src/LogoWid.cpp src/LogoWid.ui src/StyleWid.ui.h
SUBST_SED.kphotools=	-e 's|@kphotoolsdir@|${KDEDIR}/share/kde/apps/kphotools|'
SUBST_STAGE.kphotools=	post-patch

post-configure:
	${RUN}${LN} -s ${FILESDIR}/pkgsrc_fixes.h ${BUILDLINK_DIR}/include/

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
