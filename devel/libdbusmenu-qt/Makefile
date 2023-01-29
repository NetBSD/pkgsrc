# $NetBSD: Makefile,v 1.32 2023/01/29 21:14:29 ryoon Exp $

PKGREVISION= 6
.include "../../devel/libdbusmenu-qt/Makefile.common"

DISTNAME=	libdbusmenu-qt_${_VER}
PKGNAME=	${DISTNAME:S/_/-/:S/+/./}

COMMENT=	Dbusmenu library for Qt4

CMAKE_ARGS+=	-DUSE_QT4=ON

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
