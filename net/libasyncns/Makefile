# $NetBSD: Makefile,v 1.1.1.1 2009/08/25 12:18:09 wiz Exp $
#

DISTNAME=	libasyncns-0.7
CATEGORIES=	net
MASTER_SITES=	http://0pointer.de/lennart/projects/libasyncns/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/libasyncns/
COMMENT=	C library for executing name service queries asynchronously
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	libasyncns.pc.in

.include "../../mk/bsd.pkg.mk"
