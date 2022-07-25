# $NetBSD: Makefile,v 1.4 2022/07/25 11:12:26 wiz Exp $

DISTNAME=	libasyncns-0.8
CATEGORIES=	net
MASTER_SITES=	http://0pointer.de/lennart/projects/libasyncns/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/libasyncns/
COMMENT=	C library for executing name service queries asynchronously
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	libasyncns.pc.in

.include "../../mk/bsd.pkg.mk"
