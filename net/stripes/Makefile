# $NetBSD: Makefile,v 1.3 2001/05/31 19:18:18 kim Exp $
#

DISTNAME=		stripes-2.1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/sw/stripes/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.gw.com/sw/stripes/
COMMENT=		Looking Glass for Zebra and Cisco Routers

DEPENDS+=		p5-CGI>=2.66:../../www/p5-CGI
DEPENDS+=		p5-Net-Telnet>=3.02:../../net/p5-Net-Telnet

USE_PERL5=		# defined

NO_CONFIGURE=		yes
ALL_TARGET=		all DEST=${PREFIX} PERL=${PERL5} \
			CONFIGFILE=${APACHE_SYSCONFDIR}/lg.conf

BUILD_DEFS+=		APACHE_SYSCONFDIR

.include "../../mk/bsd.pkg.mk"
