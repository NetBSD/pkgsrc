# $NetBSD: Makefile,v 1.2 1999/11/24 10:33:01 agc Exp $

DISTNAME=	pptpd-1.0.0
PKGNAME=	poptop-1.0.0
CATEGORIES=	net
MASTER_SITES=	http://www.moretonbay.com/vpn/releases/
EXTRACT_SUFX=   .tgz

MAINTAINER=	dbj@netbsd.org
HOMEPAGE=	http://www.moretonbay.com/vpn/pptp.html

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-libwrap

.include "../../mk/bsd.prefs.mk"

.if defined(POPTOP_USE_MPPE)
DEPENDS+=	ppp-mppe-2.3.9:../../net/ppp-mppe
CONFIGURE_ARGS+= --with-pppd=${PREFIX}/sbin/pppd
.endif

post-patch:
	${TOUCH} ${WRKSRC}/config.h.in

.include "../../mk/bsd.pkg.mk"
