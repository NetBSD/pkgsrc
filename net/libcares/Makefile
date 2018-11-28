# $NetBSD: Makefile,v 1.25 2018/11/28 08:53:18 adam Exp $

DISTNAME=	c-ares-1.15.0
PKGNAME=	${DISTNAME:S/c-/libc/1}
CATEGORIES=	net
MASTER_SITES=	https://c-ares.haxx.se/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://c-ares.haxx.se/
COMMENT=	Asynchronous resolver library, c-ares
LICENSE=	mit

USE_LIBTOOL=		yes
USE_TOOLS+=		automake autoreconf
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libcares.pc.in

pre-configure:
	${RM} -f ${WRKSRC}/m4/xc-val-flgs.m4
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
