# $NetBSD: Makefile,v 1.82 2020/06/05 12:49:10 jperkin Exp $

DISTNAME=	kdepim-runtime-4.14.10
PKGNAME=	${DISTNAME:S/-4/4-4/}
PKGREVISION=	20
CATEGORIES=	misc
COMMENT=	Runtime requirements for the KDE PIM tools
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.04.3/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

BUILDLINK_DEPMETHOD.qt4-tools=	full

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/libkgapi/buildlink3.mk"
.include "../../devel/qjson/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
