# $NetBSD: Makefile,v 1.61 2018/07/06 15:06:48 ryoon Exp $

DISTNAME=	phonon-4.10.1

COMMENT=	Multimedia API for KDE and QT
PKGREVISION=	1

.include "Makefile.common"

.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
