# $NetBSD: Makefile,v 1.54 2016/08/04 17:03:37 ryoon Exp $

DISTNAME=	phonon-4.9.0

COMMENT=	Multimedia API for KDE and QT
PKGREVISION=	1

.include "Makefile.common"

.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
