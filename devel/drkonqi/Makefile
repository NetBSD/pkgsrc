# $NetBSD: Makefile,v 1.16 2025/10/23 20:36:18 wiz Exp $

DISTNAME=	drkonqi-${PLASMAVER}
PKGREVISION=	10
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	KDE crash handler
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/plasma5.mk"

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kidletime/buildlink3.mk"
.include "../../misc/kuserfeedback/buildlink3.mk"
.include "../../net/kxmlrpcclient/buildlink3.mk"
.include "../../textproc/syntax-highlighting/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
