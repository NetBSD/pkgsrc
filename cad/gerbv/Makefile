# $NetBSD: Makefile,v 1.48 2012/09/07 19:16:13 adam Exp $
#

DISTNAME=	gerbv-2.5.0
PKGREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gerbv/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://gerbv.sourceforge.net/
COMMENT=	Gerber file viewer
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake pkg-config

PLIST_SUBST+=	PKGNAME_NOREV=${PKGNAME_NOREV:Q}

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
