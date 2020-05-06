# $NetBSD: Makefile,v 1.46 2020/05/06 14:04:50 adam Exp $

DISTNAME=	kaccessible-16.12.0
PKGREVISION=	13
CATEGORIES=	misc
COMMENT=	Provides accessibility services like focus tracking for KDE
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
