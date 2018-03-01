# $NetBSD: Makefile,v 1.24 2018/03/01 08:56:31 adam Exp $

DISTNAME=	c-ares-1.14.0
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
