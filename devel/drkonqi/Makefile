# $NetBSD: Makefile,v 1.15 2025/04/24 14:13:29 wiz Exp $

DISTNAME=	drkonqi-${PLASMAVER}
PKGREVISION=	9
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
