# $NetBSD: Makefile,v 1.15 2003/09/22 09:39:59 wiz Exp $
#

DISTNAME=	totd-1.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	feico@pasta.cs.uit.no
HOMEPAGE=	http://www.vermicelli.pasta.cs.uit.no/ipv6/software.html
COMMENT=	DNS proxy that supports IPv6 <==> IPv4 record translation

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"
# always IPv6 ready
BUILD_DEFS+=	USE_INET6

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/totd
	${INSTALL_DATA} ${FILESDIR}/totd.conf.sample \
		${PREFIX}/share/examples/totd/totd.conf.sample

.include "../../mk/bsd.pkg.mk"
