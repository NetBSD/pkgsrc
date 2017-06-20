# $NetBSD: Makefile,v 1.20 2017/06/20 07:48:50 wiz Exp $

DISTNAME=	c-ares-1.13.0
PKGNAME=	${DISTNAME:S/c-/libc/1}
CATEGORIES=	net
MASTER_SITES=	http://c-ares.haxx.se/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://c-ares.haxx.se/
COMMENT=	Asynchronous resolver library, c-ares
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	automake

PKGCONFIG_OVERRIDE+=	libcares.pc.in

pre-configure:
	cd ${WRKSRC} && automake

.include "../../mk/bsd.pkg.mk"
