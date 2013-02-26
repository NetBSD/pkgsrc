# $NetBSD: Makefile,v 1.14 2013/02/26 23:37:32 joerg Exp $

DISTNAME=	rocs-${_KDE_VERSION}
PKGREVISION=	10
CATEGORIES=	misc
COMMENT=	KDE graph theory IDE

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-std=c++11
.endif

.include "../../mk/bsd.pkg.mk"
