# $NetBSD: Makefile,v 1.32 2017/01/01 16:06:27 adam Exp $

DISTNAME=	kaccessible-15.12.0
PKGREVISION=	3
CATEGORIES=	misc
COMMENT=	Provides accessibility services like focus tracking for KDE
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
