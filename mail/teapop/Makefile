# $NetBSD: Makefile,v 1.2 2001/04/03 05:52:00 zuntum Exp $

DISTNAME=	teapop-0.3.0
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.toontown.org/pub/teapop/			\
		http://www.toontown.org/pub/teapop/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.toontown.org/teapop/
COMMENT=	Yet another RFC1939 compliant POP3 server

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-flock
CONFIGURE_ARGS+=--sysconfdir=/etc

.include "../../mk/bsd.prefs.mk"

.if defined(TEAPOP_WITHOUT_APOP)
CONFIGURE_ARGS+=--disable-apop
.endif

.if defined(TEAPOP_WITHOUT_VPOP)
CONFIGURE_ARGS+=--disable-vpop
.endif

.include "../../mk/bsd.pkg.mk"
