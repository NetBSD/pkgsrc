# $NetBSD: Makefile,v 1.1 2014/09/04 19:46:34 fhajny Exp $

DISTNAME=	liblogging-1.0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://download.rsyslog.com/liblogging/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.liblogging.org/
COMMENT=	Easy to use logging library
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	rfc3195/liblogging-rfc3195.pc.in
PKGCONFIG_OVERRIDE+=	stdlog/liblogging-stdlog.pc.in

CONFIGURE_ARGS+=	--disable-journal
CONFIGURE_ARGS+=	--enable-stdlog

.include "../../mk/bsd.pkg.mk"
