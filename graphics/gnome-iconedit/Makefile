# $NetBSD: Makefile,v 1.8 2002/07/14 13:49:11 wiz Exp $
#

DISTNAME=		gnome-iconedit-1.2.0
PKGREVISION=		1
CATEGORIES=		graphics gnome
MASTER_SITES=		http://www.webtribe.net/i/iain/

MAINTAINER=		wiz@netbsd.org
COMMENT=		icon editor based on GNOME libraries

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_X11BASE=		YES
USE_BUILDLINK_ONLY=	YES

post-configure:
	cd ${WRKSRC}/src && ${GMAKE} clean

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/oaf/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
