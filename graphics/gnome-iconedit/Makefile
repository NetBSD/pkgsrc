# $NetBSD: Makefile,v 1.24 2005/05/22 20:08:05 jlam Exp $
#

DISTNAME=		gnome-iconedit-1.2.0
PKGREVISION=		7
CATEGORIES=		graphics gnome
MASTER_SITES=		http://www.webtribe.net/i/iain/

MAINTAINER=		wiz@NetBSD.org
COMMENT=		Icon editor based on GNOME libraries

BUILD_USES_MSGFMT=	YES

USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

post-configure:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} clean

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
