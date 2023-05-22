# $NetBSD: Makefile,v 1.5 2023/05/22 21:00:01 wiz Exp $

DISTNAME=	qtlottie-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtlottie-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt6 module for lottie animations
CATEGORIES=	graphics
LICENSE=	gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
