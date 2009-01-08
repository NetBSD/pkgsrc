# $NetBSD: Makefile,v 1.6 2009/01/08 12:02:44 wiz Exp $
#

DISTNAME=		kchmviewer-4.0
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kchmviewer/}

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www.kchmviewer.net/
COMMENT=		KchmViewer is a CHM (MS HTML help file format) viewer

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

.include "options.mk"

.include "../../devel/chmlib/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
