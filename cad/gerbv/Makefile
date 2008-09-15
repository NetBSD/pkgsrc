# $NetBSD: Makefile,v 1.34 2008/09/15 02:25:54 dmcmahill Exp $
#

DISTNAME=	gerbv-2.1.0
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gerbv/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://gerbv.sourceforge.net/
COMMENT=	Gerber file viewer

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
