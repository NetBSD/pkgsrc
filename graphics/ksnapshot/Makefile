# $NetBSD: Makefile,v 1.29 2015/09/23 12:04:37 joerg Exp $

DISTNAME=	ksnapshot-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	graphics
COMMENT=	KDE screen capture program

# CMakeFiles/kbackgroundsnapshot.dir/snapshottimer.o: In function `SnapshotTimer':
# /data/scratch/graphics/ksnapshot/work/ksnapshot-4.14.3/snapshottimer.cpp:33: undefined reference to `vtable for SnapshotTimer'
# ...
MAKE_JOBS_SAFE=	no

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
