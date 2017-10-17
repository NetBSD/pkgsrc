# $NetBSD: Makefile,v 1.6 2017/10/17 11:42:30 fhajny Exp $

DISTNAME=	libfastjson-0.99.7
CATEGORIES=	textproc
MASTER_SITES=	http://download.rsyslog.com/libfastjson/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/rsyslog/libfastjson/
COMMENT=	Fast json library for C
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c99
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libfastjson.pc.in

.include "../../mk/bsd.pkg.mk"
