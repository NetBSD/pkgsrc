# $NetBSD: Makefile,v 1.15 2012/10/23 19:51:07 asau Exp $
#

DISTNAME=		hal-info-20091130
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://hal.freedesktop.org/releases/

MAINTAINER=		netbsd-desktop@NetBSD.org
HOMEPAGE=		http://hal.freedesktop.org/
COMMENT=		FreeDesktop hardware abstraction layer (info subpackage)
LICENSE=		gnu-gpl-v2 # OR Academic-Free-License-v2.1

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
