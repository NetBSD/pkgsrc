# $NetBSD: Makefile,v 1.5 2001/11/25 19:18:32 jlam Exp $
#

DISTNAME=		stripes-2.1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/sw/stripes/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.gw.com/sw/stripes/
COMMENT=		Looking Glass for Zebra and Cisco Routers

DEPENDS+=		{p5-CGI>=2.66,perl>=5.6.1nb2}:../../www/p5-CGI
DEPENDS+=		p5-Net-Telnet>=3.02:../../net/p5-Net-Telnet

USE_PERL5=		# defined

PKG_SYSCONFSUBDIR?=	httpd
ALL_TARGET=		all DEST=${PREFIX} PERL=${PERL5} \
			CONFIGFILE=${PKG_SYSCONFDIR}/lg.conf

.include "../../mk/bsd.pkg.mk"
