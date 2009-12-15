# $NetBSD: Makefile,v 1.12 2009/12/15 10:37:02 wiz Exp $
#

DISTNAME=		hal-info-20091130
CATEGORIES=		sysutils
MASTER_SITES=		http://hal.freedesktop.org/releases/

MAINTAINER=		netbsd-desktop@NetBSD.org
HOMEPAGE=		http://hal.freedesktop.org/
COMMENT=		FreeDesktop hardware abstraction layer (info subpackage)
LICENSE=		gnu-gpl-v2 # OR Academic-Free-License-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

.include "../../mk/bsd.pkg.mk"
