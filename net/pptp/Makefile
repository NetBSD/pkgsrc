# $NetBSD: Makefile,v 1.2 2001/02/17 18:19:29 wiz Exp $

DISTNAME=	pptp-linux-1.0.2
PKGNAME=	pptp-1.0.2
CATEGORIES=	net
MASTER_SITES= 	http://www.pdos.lcs.mit.edu/~cananian/Synaptics/release/
#EXTRACT_SUFX=   .tar.gz

MAINTAINER=	jtk@netbsd.org
HOMEPAGE=	http://www.pdos.lcs.mit.edu/~cananian/Projects/PPTP/
COMMENT=	PPTP client package for Microsoft VPN servers (no encryption yet)

#LICENSE=	GPL

.include "../../mk/bsd.prefs.mk"

# Not quite yet---special config for MPPE in pppd.
#.if defined(PPTP_USE_MPPE)
#DEPENDS+=	ppp-mppe-2.3.9:../../net/ppp-mppe
#CONFIGURE_ARGS+= --with-pppd=${PREFIX}/sbin/pppd
#.endif

.include "../../mk/bsd.pkg.mk"
