# $NetBSD: Makefile,v 1.29 2016/01/10 19:45:09 markd Exp $

DISTNAME=	ksaneplugin-15.12.0
CATEGORIES=	graphics
COMMENT=	SANE Plugin for KDE
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/libksane/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
