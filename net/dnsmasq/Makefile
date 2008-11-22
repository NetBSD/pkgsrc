# $NetBSD: Makefile,v 1.8 2008/11/22 18:59:54 ahoka Exp $
#

DISTNAME=		dnsmasq-2.45
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		http://www.thekelleys.org.uk/dnsmasq/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.thekelleys.org.uk/dnsmasq/doc.html
COMMENT=		Lightweight, easy to configure DNS forwarder

USE_TOOLS+=		gmake

RCD_SCRIPTS=	dnsmasq
CONF_FILES=	${PREFIX}/share/examples/dnsmasq/dnsmasq.conf.example \
		${PKG_SYSCONFDIR}/dnsmasq.conf

CFLAGS+=	-DCONFFILE=\"${PKG_SYSCONFDIR}/dnsmasq.conf\"
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dnsmasq
	${INSTALL} ${WRKSRC}/dnsmasq.conf.example \
		${PREFIX}/share/examples/dnsmasq/

.include "../../mk/bsd.pkg.mk"
