# $NetBSD: Makefile,v 1.24 2019/08/11 13:22:30 wiz Exp $

DISTNAME=		stripes-2.1
PKGREVISION=		8
CATEGORIES=		net
MASTER_SITES=		# ftp://ftp.gw.com/sw/stripes/

MAINTAINER=		kim@tac.nyc.ny.us
#HOMEPAGE=		http://www.gw.com/sw/stripes/
COMMENT=		Looking Glass for Zebra and Cisco Routers

DEPENDS+=		p5-CGI>=2.66:../../www/p5-CGI
DEPENDS+=		p5-Net-Telnet>=3.02:../../net/p5-Net-Telnet

PKG_SYSCONFSUBDIR?=	httpd
BUILD_TARGET=		all
MAKE_FLAGS+=		DEST=${PREFIX:Q} PERL=${PERL5:Q} \
			CONFIGFILE=${PKG_SYSCONFDIR}/lg.conf
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}/man8

USE_TOOLS+=		perl:run
REPLACE_PERL=		lg.pl

INSTALLATION_DIRS=	libexec/cgi-bin ${PKGMANDIR}/man8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lg ${DESTDIR}${PREFIX}/libexec/cgi-bin
	${INSTALL_MAN} ${WRKSRC}/lg.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
