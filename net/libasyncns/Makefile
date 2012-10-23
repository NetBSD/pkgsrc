# $NetBSD: Makefile,v 1.2 2012/10/23 17:18:32 asau Exp $
#

DISTNAME=	libasyncns-0.7
CATEGORIES=	net
MASTER_SITES=	http://0pointer.de/lennart/projects/libasyncns/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/libasyncns/
COMMENT=	C library for executing name service queries asynchronously
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	libasyncns.pc.in

.include "../../mk/bsd.pkg.mk"
