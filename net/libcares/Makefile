# $NetBSD: Makefile,v 1.15 2012/11/22 11:38:20 ryoon Exp $
#

DISTNAME=	c-ares-1.9.1
PKGNAME=	libcares-1.9.1
CATEGORIES=	net
MASTER_SITES=	http://c-ares.haxx.se/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://c-ares.haxx.se/
COMMENT=	Asynchronous resolver library, c-ares
LICENSE=	mit

CONFLICTS+=	libares-[0-9]*

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

PKGCONFIG_OVERRIDE+=	libcares.pc.in

.include "../../mk/bsd.pkg.mk"
