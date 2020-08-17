# $NetBSD: Makefile,v 1.50 2020/08/17 20:19:30 leot Exp $

DISTNAME=	kaccessible-16.12.0
PKGREVISION=	17
CATEGORIES=	misc
COMMENT=	Provides accessibility services like focus tracking for KDE
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
