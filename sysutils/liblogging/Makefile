# $NetBSD: Makefile,v 1.6 2022/07/25 11:12:28 wiz Exp $

DISTNAME=	liblogging-1.0.6
CATEGORIES=	sysutils
MASTER_SITES=	https://download.rsyslog.com/liblogging/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.liblogging.org/
COMMENT=	Easy to use logging library
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	rfc3195/liblogging-rfc3195.pc.in
PKGCONFIG_OVERRIDE+=	stdlog/liblogging-stdlog.pc.in

CONFIGURE_ARGS+=	--disable-journal
CONFIGURE_ARGS+=	--enable-stdlog

.include "../../mk/bsd.pkg.mk"
