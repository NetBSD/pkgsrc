# $NetBSD: Makefile,v 1.52 2016/03/05 11:27:51 jperkin Exp $

DISTNAME=	phonon-4.8.3
PKGREVISION=	3

COMMENT=	Multimedia API for KDE and QT

.include "Makefile.common"

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
