# $NetBSD: Makefile,v 1.8 2006/03/04 21:30:23 jlam Exp $

DISTNAME=	pptp-linux-1.0.2
PKGNAME=	pptp-1.0.2
CATEGORIES=	net
MASTER_SITES= 	http://www.pdos.lcs.mit.edu/~cananian/Synaptics/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pdos.lcs.mit.edu/~cananian/Projects/PPTP/
COMMENT=	PPTP client package for Microsoft VPN servers (no encryption yet)

#LICENSE=	GPL

NOT_FOR_PLATFORM=	Interix-*-*

.include "../../mk/bsd.prefs.mk"

# Not quite yet---special config for MPPE in pppd.
#.if defined(PPTP_USE_MPPE)
#DEPENDS+=	ppp-mppe-2.3.9:../../net/ppp-mppe
#CONFIGURE_ARGS+= --with-pppd=${PREFIX}/sbin/pppd
#.endif

.include "../../mk/bsd.pkg.mk"
