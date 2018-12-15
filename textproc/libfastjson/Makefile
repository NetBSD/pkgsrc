# $NetBSD: Makefile,v 1.8 2018/12/15 21:12:24 wiz Exp $

DISTNAME=	libfastjson-0.99.8
CATEGORIES=	textproc
MASTER_SITES=	http://download.rsyslog.com/libfastjson/

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	https://github.com/rsyslog/libfastjson/
COMMENT=	Fast json library for C
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c99
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libfastjson.pc.in

.include "../../mk/bsd.pkg.mk"
