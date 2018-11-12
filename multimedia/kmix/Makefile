# $NetBSD: Makefile,v 1.48 2018/11/12 03:52:38 ryoon Exp $

DISTNAME=	kmix-${_KDE_VERSION}
PKGREVISION=	23
CATEGORIES=	multimedia
COMMENT=	KDE's soundcard mixer program

# lib/libkdeinit4_kmixctrl.so: undefined reference to `vtable for ControlAdaptor'
MAKE_JOBS_SAFE=	no

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
