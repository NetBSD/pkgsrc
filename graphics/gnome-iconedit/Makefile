# $NetBSD: Makefile,v 1.18 2004/03/08 19:40:39 jmmv Exp $
#

DISTNAME=		gnome-iconedit-1.2.0
PKGREVISION=		5
CATEGORIES=		graphics gnome
MASTER_SITES=		http://www.webtribe.net/i/iain/

MAINTAINER=		wiz@NetBSD.org
COMMENT=		Icon editor based on GNOME libraries

BUILD_USES_MSGFMT=	YES
DEPENDS+=		gnome1-dirs>=1.5:../../misc/gnome1-dirs

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES

post-configure:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} clean

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
