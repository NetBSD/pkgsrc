# $NetBSD: Makefile,v 1.5 2020/05/27 19:37:42 wiz Exp $

DISTNAME=	liblogging-1.0.6
CATEGORIES=	sysutils
MASTER_SITES=	https://download.rsyslog.com/liblogging/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
