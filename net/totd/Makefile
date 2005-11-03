# $NetBSD: Makefile,v 1.18 2005/11/03 16:55:26 tv Exp $
#

DISTNAME=	totd-1.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	feico@pasta.cs.uit.no
HOMEPAGE=	http://www.vermicelli.pasta.cs.uit.no/ipv6/software.html
COMMENT=	DNS proxy that supports IPv6 <==> IPv4 record translation

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/totd
	${INSTALL_DATA} ${FILESDIR}/totd.conf.sample \
		${PREFIX}/share/examples/totd/totd.conf.sample

PKG_OPTIONS_VAR=		PKG_OPTIONS.sipcalc
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"
