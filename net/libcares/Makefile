# $NetBSD: Makefile,v 1.17 2016/09/29 14:19:59 wiz Exp $

DISTNAME=	c-ares-1.12.0
PKGNAME=	${DISTNAME:S/c-/libc/1}
CATEGORIES=	net
MASTER_SITES=	http://c-ares.haxx.se/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://c-ares.haxx.se/
COMMENT=	Asynchronous resolver library, c-ares
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
MAKE_JOBS_SAFE=	no

PKGCONFIG_OVERRIDE+=	libcares.pc.in

.include "../../mk/bsd.pkg.mk"
