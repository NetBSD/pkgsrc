# $NetBSD: Makefile,v 1.30 2012/10/02 17:11:50 tron Exp $
#

DISTNAME=	epdfview-0.1.8
PKGREVISION=	8
CATEGORIES=	print
MASTER_SITES=	http://trac.emma-soft.com/epdfview/chrome/site/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://trac.emma-soft.com/epdfview/
COMMENT=	Lightweight PDF viewer using Poppler and GTK2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt

.include "options.mk"

.include "../../print/poppler-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
