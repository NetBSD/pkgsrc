# $NetBSD: Makefile,v 1.32 2008/02/18 22:40:36 dmcmahill Exp $
#

DISTNAME=	gerbv-2.0.1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gerbv/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://gerbv.sourceforge.net/
COMMENT=	Gerber file viewer

PKG_INSTALLATION_TYPES= overwrite pkgviews

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config
#CONFIGURE_ARGS+=	--disable-update-desktop-database

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
