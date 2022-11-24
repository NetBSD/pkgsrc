# $NetBSD: Makefile,v 1.2 2022/11/24 11:26:19 nros Exp $

DISTNAME=	qt6-${QTVERSION}

COMMENT=	"meta-package" for version 6 of the QT GUI C++ toolkit

CATEGORIES=	meta-pkgs

META_PACKAGE=	yes

.include "Makefile.common"

DEPENDS+=	qt6-odbc-${QTVERSION}{,nb[0-9]*}:../../databases/qt6-odbc
DEPENDS+=	qt6-qtbase-${QTVERSION}{,nb[0-9]*}:../../x11/qt6-qtbase

.include "../../mk/bsd.pkg.mk"
