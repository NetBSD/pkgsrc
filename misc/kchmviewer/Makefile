# $NetBSD: Makefile,v 1.4 2008/01/18 05:08:35 tnn Exp $
#

DISTNAME=		kchmviewer-3.1
PKGREVISION=		3
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kchmviewer/}

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www.kchmviewer.net/
COMMENT=		KchmViewer is a CHM (MS HTML help file format) viewer

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-kde

.include "../../devel/chmlib/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../mk/bsd.pkg.mk"
