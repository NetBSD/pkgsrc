# $NetBSD: Makefile,v 1.11 2022/07/25 11:12:29 wiz Exp $

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

PKGCONFIG_OVERRIDE+=	libfastjson.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# NetBSD libc without compat modf in libc requires libm
LIBS+=		-lm
.endif

.include "../../mk/bsd.pkg.mk"
