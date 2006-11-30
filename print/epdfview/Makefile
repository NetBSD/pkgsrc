# $NetBSD: Makefile,v 1.1.1.1 2006/11/30 07:30:29 reed Exp $
#

DISTNAME=	epdfview-0.1.5
CATEGORIES=	print
MASTER_SITES=	http://trac.emma-soft.com/epdfview/chrome/site/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://trac.emma-soft.com/epdfview/
COMMENT=	Lightweight PDF viewer using Poppler and GTK2

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

.include "../../print/poppler-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

# XXX Should this be used?
# .include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
