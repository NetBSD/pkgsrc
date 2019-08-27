# $NetBSD: Makefile,v 1.62 2019/08/27 06:39:24 markd Exp $

DISTNAME=	phonon-4.10.3

COMMENT=	Multimedia API for KDE and QT

.include "Makefile.common"

.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
