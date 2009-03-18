# $NetBSD: Makefile,v 1.6 2009/03/18 13:30:46 jmcneill Exp $
#

DISTNAME=		hal-info-20090202
CATEGORIES=		sysutils
MASTER_SITES=		http://hal.freedesktop.org/releases/

MAINTAINER=		netbsd-desktop@NetBSD.org
HOMEPAGE=		http://hal.freedesktop.org/
COMMENT=		FreeDesktop hardware abstraction layer (info subpackage)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.4
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

.include "../../mk/bsd.pkg.mk"
