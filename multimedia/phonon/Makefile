# $NetBSD: Makefile,v 1.80 2025/02/12 06:45:28 ryoon Exp $

DISTNAME=	phonon-4.10.3

COMMENT=	Multimedia API for KDE and QT
PKGREVISION=	18

.include "Makefile.common"

.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
