# $NetBSD: Makefile,v 1.21 2004/04/25 04:16:43 xtraeme Exp $
#

DISTNAME=		gnome-iconedit-1.2.0
PKGREVISION=		6
CATEGORIES=		graphics gnome
MASTER_SITES=		http://www.webtribe.net/i/iain/

MAINTAINER=		wiz@NetBSD.org
COMMENT=		Icon editor based on GNOME libraries

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3=		YES
USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES

post-configure:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} clean

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
