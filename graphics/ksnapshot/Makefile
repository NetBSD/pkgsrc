# $NetBSD: Makefile,v 1.31 2016/03/05 11:28:39 jperkin Exp $

DISTNAME=	ksnapshot-15.08.3
PKGREVISION=	1
CATEGORIES=	graphics
COMMENT=	KDE screen capture program
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.08.3/src/}

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
