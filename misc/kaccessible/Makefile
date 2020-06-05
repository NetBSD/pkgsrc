# $NetBSD: Makefile,v 1.49 2020/06/05 12:49:10 jperkin Exp $

DISTNAME=	kaccessible-16.12.0
PKGREVISION=	16
CATEGORIES=	misc
COMMENT=	Provides accessibility services like focus tracking for KDE
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
