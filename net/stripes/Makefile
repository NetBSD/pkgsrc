# $NetBSD: Makefile,v 1.11 2005/12/05 20:50:49 rillig Exp $
#

DISTNAME=		stripes-2.1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.gw.com/sw/stripes/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.gw.com/sw/stripes/
COMMENT=		Looking Glass for Zebra and Cisco Routers

DEPENDS+=		{p5-CGI>=2.66,perl>=5.6.1nb2}:../../www/p5-CGI
DEPENDS+=		p5-Net-Telnet>=3.02:../../net/p5-Net-Telnet

PKG_SYSCONFSUBDIR?=	httpd
BUILD_TARGET=		all
MAKE_FLAGS+=		DEST=${PREFIX:Q} PERL=${PERL5:Q} \
			CONFIGFILE=${PKG_SYSCONFDIR}/lg.conf

USE_TOOLS+=		perl:run
REPLACE_PERL=		lg.pl

.include "../../mk/bsd.pkg.mk"
