# $NetBSD: Makefile,v 1.3 2016/02/09 11:30:47 mef Exp $
#

DISTNAME=	libasyncns-0.8
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
