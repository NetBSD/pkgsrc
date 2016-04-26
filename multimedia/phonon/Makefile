# $NetBSD: Makefile,v 1.53 2016/04/26 08:08:50 markd Exp $

DISTNAME=	phonon-4.9.0

COMMENT=	Multimedia API for KDE and QT

.include "Makefile.common"

.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
