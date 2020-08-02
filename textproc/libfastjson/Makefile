# $NetBSD: Makefile,v 1.10 2020/08/02 12:08:35 jmcneill Exp $

DISTNAME=	libfastjson-0.99.8
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://download.rsyslog.com/libfastjson/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rsyslog/libfastjson/
COMMENT=	Fast json library for C
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c99
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libfastjson.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# NetBSD libc without compat modf in libc requires libm
LIBS+=		-lm
.endif

.include "../../mk/bsd.pkg.mk"
