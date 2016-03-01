# $NetBSD: Makefile,v 1.51 2016/03/01 08:54:42 markd Exp $

DISTNAME=	phonon-4.8.3
PKGREVISION=	2

COMMENT=	Multimedia API for KDE and QT

.include "Makefile.common"

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
