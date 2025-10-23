# $NetBSD: Makefile,v 1.37 2025/10/23 20:36:29 wiz Exp $

PKGREVISION= 10
.include "../../devel/libdbusmenu-qt/Makefile.common"

DISTNAME=	libdbusmenu-qt_${_VER}
PKGNAME=	${DISTNAME:S/_/-/:S/+/./}

COMMENT=	Dbusmenu library for Qt4

CMAKE_CONFIGURE_ARGS+=	-DUSE_QT4=ON

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
