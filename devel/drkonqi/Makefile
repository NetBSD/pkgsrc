# $NetBSD: Makefile,v 1.5 2024/01/30 14:21:38 ryoon Exp $

DISTNAME=	drkonqi-${PLASMAVER}
PKGREVISION=	4
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	KDE crash handler
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/plasma5.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kidletime/buildlink3.mk"
.include "../../net/kxmlrpcclient/buildlink3.mk"
.include "../../textproc/syntax-highlighting/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
