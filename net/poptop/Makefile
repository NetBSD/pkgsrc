# $NetBSD: Makefile,v 1.6 2003/07/17 22:51:39 grant Exp $
#

DISTNAME=	pptpd-1.0.1
PKGNAME=	${DISTNAME:S/pptpd/poptop/}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.snapgear.com/poptop/

MAINTAINER=	dbj@NetBSD.org
HOMEPAGE=	http://www.snapgear.com/vpn/pptp.html
COMMENT=	PPTP server with support for Microsoft VPN clients

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-libwrap

.include "../../mk/bsd.prefs.mk"

.if defined(POPTOP_USE_MPPE)
DEPENDS+=		ppp-mppe-2.3.9:../../net/ppp-mppe
CONFIGURE_ARGS+=	--with-pppd=${PREFIX}/sbin/pppd
.endif

.include "../../mk/bsd.pkg.mk"
