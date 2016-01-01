# $NetBSD: Makefile,v 1.1 2016/01/01 15:25:43 fhajny Exp $

DISTNAME=	libfastjson-0.99.0
CATEGORIES=	textproc
MASTER_SITES=	http://download.rsyslog.com/libfastjson/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/rsyslog/libfastjson/
COMMENT=	Fast json library for C
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libfastjson.pc.in

.include "../../mk/bsd.pkg.mk"
