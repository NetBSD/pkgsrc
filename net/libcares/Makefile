# $NetBSD: Makefile,v 1.23 2017/08/16 20:21:13 wiz Exp $

DISTNAME=	c-ares-1.13.0
PKGNAME=	${DISTNAME:S/c-/libc/1}
CATEGORIES=	net
MASTER_SITES=	https://c-ares.haxx.se/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://c-ares.haxx.se/
COMMENT=	Asynchronous resolver library, c-ares
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	automake

PKGCONFIG_OVERRIDE+=	libcares.pc.in

pre-configure:
	${RM} -f ${WRKSRC}/m4/xc-val-flgs.m4
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
