# $NetBSD: Makefile,v 1.71 2021/12/08 16:02:25 adam Exp $

DISTNAME=	phonon-4.10.3

COMMENT=	Multimedia API for KDE and QT
PKGREVISION=	9

.include "Makefile.common"

.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
