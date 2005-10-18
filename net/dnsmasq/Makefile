# $NetBSD: Makefile,v 1.1.1.1 2005/10/18 04:41:59 minskim Exp $
#

DISTNAME=		dnsmasq-2.23
CATEGORIES=		net
MASTER_SITES=		http://www.thekelleys.org.uk/dnsmasq/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.thekelleys.org.uk/dnsmasq/doc.html
COMMENT=		Lightweight, easy to configure DNS forwarder

USE_TOOLS+=		gmake
USE_PKGINSTALL= 	yes

RCD_SCRIPTS=	dnsmasq
CONF_FILES=	${PREFIX}/share/examples/dnsmasq/dnsmasq.conf.example \
		${PKG_SYSCONFDIR}/dnsmasq.conf
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dnsmasq
	${INSTALL} ${WRKSRC}/dnsmasq.conf.example \
		${PREFIX}/share/examples/dnsmasq/

.include "../../mk/bsd.pkg.mk"
