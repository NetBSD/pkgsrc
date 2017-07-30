# $NetBSD: Makefile,v 1.5 2017/07/30 22:32:23 wiz Exp $

DISTNAME=	libfastjson-0.99.6
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
