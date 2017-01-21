# $NetBSD: Makefile,v 1.55 2017/01/21 20:06:51 ryoon Exp $

DISTNAME=	phonon-4.9.0

COMMENT=	Multimedia API for KDE and QT
PKGREVISION=	2

.include "Makefile.common"

.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
