# $NetBSD: Makefile,v 1.6 2022/11/24 16:29:15 nros Exp $

DISTNAME=	qt6-${QTVERSION}

COMMENT=	"meta-package" for version 6 of the QT GUI C++ toolkit

CATEGORIES=	meta-pkgs

META_PACKAGE=	yes

.include "Makefile.common"

DEPENDS+=	qt6-odbc-${QTVERSION}{,nb[0-9]*}:../../databases/qt6-odbc
DEPENDS+=	qt6-psql-${QTVERSION}{,nb[0-9]*}:../../databases/qt6-psql
DEPENDS+=	qt6-qtimageformats-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtimageformats
DEPENDS+=	qt6-qtshadertools-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtshadertools
DEPENDS+=	qt6-qtsvg-${QTVERSION}{,nb[0-9]*}:../../graphics/qt6-qtsvg
DEPENDS+=	qt6-qtbase-${QTVERSION}{,nb[0-9]*}:../../x11/qt6-qtbase

.include "../../mk/bsd.pkg.mk"
