# $NetBSD: Makefile,v 1.9 2004/04/25 08:10:20 snj Exp $
#

DISTNAME=	pptpd-1.1.3-20030409
PKGNAME=	poptop-1.1.3.20030409
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poptop/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.poptop.org/
COMMENT=	PPTP server with support for Microsoft VPN clients

WRKSRC=		${WRKDIR}/poptop
USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-libwrap

.include "../../mk/bsd.prefs.mk"

.if defined(POPTOP_USE_MPPE)
DEPENDS+=		ppp-mppe-2.3.9:../../net/ppp-mppe
CONFIGURE_ARGS+=	--with-pppd=${PREFIX}/sbin/pppd
.endif

.include "../../mk/bsd.pkg.mk"
