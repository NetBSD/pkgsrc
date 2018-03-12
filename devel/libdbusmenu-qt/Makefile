# $NetBSD: Makefile,v 1.27 2018/03/12 11:15:29 wiz Exp $

PKGREVISION= 1
.include "../../devel/libdbusmenu-qt/Makefile.common"

DISTNAME=	libdbusmenu-qt_${_VER}
PKGNAME=	${DISTNAME:S/_/-/:S/+/./}

COMMENT=	Dbusmenu library for Qt4

CMAKE_ARGS+=	-DUSE_QT4=ON

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
