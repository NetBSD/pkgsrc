# $NetBSD: Makefile,v 1.1.1.1 2009/10/02 21:33:16 markd Exp $

DISTNAME=	kdeutils-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Utilities for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

PYTHON_VERSIONS_ACCEPTED= 26 25
#make sure cmake picks up the same Python version as pkgsrc
CMAKE_ARGS+=	-DPYTHON_EXECUTABLE:FILEPATH=${PYTHONBIN}

# BUILD_MAKE_FLAGS+= VERBOSE=1

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../print/py-cups/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kdelibs-experimental4/buildlink3.mk"
.include "../../x11/kdebase4/buildlink3.mk"
.include "../../x11/kdebase-runtime4/buildlink3.mk"
.include "../../x11/kdebase-workspace4/buildlink3.mk"
.include "../../x11/kdebindings4-python/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
