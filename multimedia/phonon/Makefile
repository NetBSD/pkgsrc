# $NetBSD: Makefile,v 1.57 2018/01/17 19:44:06 markd Exp $

DISTNAME=	phonon-4.9.1

COMMENT=	Multimedia API for KDE and QT

.include "Makefile.common"

.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
