# $NetBSD: Makefile,v 1.19 2011/11/01 06:02:06 sbd Exp $

DISTNAME=	kdeedu-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	misc
COMMENT=	Edu{tainment,cation} tools for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

CMAKE_ARGS+=	-DBUILD_kmplot:BOOL=OFF
CMAKE_ARGS+=	-DWITH_SBIG:BOOL=OFF
CMAKE_ARGS+=	-DWITH_R:BOOL=OFF
# CMAKE_ARGS+=	-DWITH_PyKDE4:BOOL=OFF   # "sip: MarblePlacemarkModel is undefined"
#XXX detection does not work reliably
CMAKE_ARGS+=	-DWITH_BoostPython:BOOL=OFF
# eigen2.0.4 tries to use _M_erase_at_end - not defined.
CMAKE_ARGS+=	-DBUILD_step:BOOL=OFF

USE_GNU_READLINE=	yes
BROKEN_READLINE_DETECTION=	yes

REPLACE_PYTHON+=	kig/pykig/pykig.py

.include "../../meta-pkgs/kde4/kde4.mk"

#.include "../../lang/python/application.mk"
#.include "../../devel/boost-python/buildlink3.mk"
.include "../../devel/cfitsio/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
#BUILDLINK_API_DEPENDS.eigen2+=	eigen2>=2.0.3
#.include "../../math/eigen2/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kdebase-runtime4/buildlink3.mk"
.include "../../x11/kdebase-workspace4/buildlink3.mk"
.include "../../x11/kdebindings4-python/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
