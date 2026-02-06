# $NetBSD: Makefile,v 1.4 2026/02/06 10:05:50 wiz Exp $

DISTNAME=	ksshaskpass-${PLASMAVER}
PKGREVISION=	3
CATEGORIES=	security

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	ssh-add helper that uses kwallet and kpassworddialog
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/plasma6.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../security/kf6-kwallet/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
