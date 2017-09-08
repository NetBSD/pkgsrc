# $NetBSD: Makefile,v 1.56 2017/09/08 02:38:42 ryoon Exp $

DISTNAME=	phonon-4.9.0

COMMENT=	Multimedia API for KDE and QT
PKGREVISION=	3

.include "Makefile.common"

.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
