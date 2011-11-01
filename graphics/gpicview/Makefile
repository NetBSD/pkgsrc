# $NetBSD: Makefile,v 1.2 2011/11/01 16:56:27 ryoon Exp $

DISTNAME=	gpicview-0.2.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lxde/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxde.sourceforge.net/gpicview/
COMMENT=	Lightweight image viewer
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake intltool

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
