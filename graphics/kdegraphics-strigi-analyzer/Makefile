# $NetBSD: Makefile,v 1.57 2021/12/08 16:04:58 adam Exp $

DISTNAME=	kdegraphics-strigi-analyzer-16.04.0
PKGREVISION=	23
CATEGORIES=	graphics
COMMENT=	Graphics file format plugins for Strigi Desktop Search
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.04.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
