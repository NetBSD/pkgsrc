# $NetBSD: Makefile,v 1.8 2005/10/02 05:09:52 seb Exp $

DISTNAME=	kipi-plugins-0.1.0-beta2
PKGNAME=	kipi-plugins-0.1.0beta2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/unstable/apps/KDE3.x/graphics/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	seb@NetBSD.ORG
HOMEPAGE=	http://extragear.kde.org/apps/kipi/
COMMENT=	Kipi (KDE Image Plugin Interface) plugins

DEPENDS+=	dcraw-[0-9]*:../../graphics/dcraw
DEPENDS+=	bash-[0-9]*:../../shells/bash2

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	libtool

# This is a gross hack...
pre-build:
	${MV} ${BUILDLINK_DIR}/include/kpopupmenu.h		\
		${BUILDLINK_DIR}/include/kpopupmenu.h.orig
	${SED} -e 's,=NULL,=(QPixmap*)NULL,'			\
		${BUILDLINK_DIR}/include/kpopupmenu.h.orig	\
		> ${BUILDLINK_DIR}/include/kpopupmenu.h

# a fix for qt-3.3.5, please remove if qt-3.3.6 (or newer) solves the problem
SUBST_CLASSES+=		hints
SUBST_STAGE.hints=	post-patch
SUBST_MESSAGE.hints=	"Fix includehints."
SUBST_FILES.hints=	kipi-plugins/printwizard/frmprintwizardbase.ui
SUBST_FILTER_CMD.hints=	${GREP} -v includehint

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/libkexif/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
#.include "../../x11/kdebase3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
