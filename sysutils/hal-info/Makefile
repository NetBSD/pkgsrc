# $NetBSD: Makefile,v 1.14 2012/10/03 21:57:38 wiz Exp $
#

DISTNAME=		hal-info-20091130
PKGREVISION=		1
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

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
