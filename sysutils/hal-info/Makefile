# $NetBSD: Makefile,v 1.9 2009/05/19 08:59:34 wiz Exp $
#

DISTNAME=		hal-info-20090414
CATEGORIES=		sysutils
MASTER_SITES=		http://hal.freedesktop.org/releases/

MAINTAINER=		netbsd-desktop@NetBSD.org
HOMEPAGE=		http://hal.freedesktop.org/
COMMENT=		FreeDesktop hardware abstraction layer (info subpackage)
#LICENSE=		Academic-Free-License-v2.1 OR gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.4
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

.include "../../mk/bsd.pkg.mk"
