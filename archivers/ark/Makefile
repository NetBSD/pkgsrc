# $NetBSD: Makefile,v 1.1.1.1 2012/03/20 00:55:51 markd Exp $

DISTNAME=	ark-${_KDE_VERSION}
CATEGORIES=	archivers
COMMENT=	for managing various archive formats within the KDE environment

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-baseapps4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
