# $NetBSD: Makefile,v 1.7 2003/09/17 19:37:08 cube Exp $
#

DISTNAME=	pptpd-1.1.3-20030409
PKGNAME=	poptop-1.1.3.20030409
WRKSRC=		${WRKDIR}/poptop
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poptop/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.poptop.org/
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
