# $NetBSD: Makefile,v 1.13 2002/03/15 01:54:15 itojun Exp $
#

DISTNAME=	totd-1.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	feico@pasta.cs.uit.no
HOMEPAGE=	http://www.vermicelli.pasta.cs.uit.no/ipv6/software.html
COMMENT=	DNS proxy that supports IPv6 <==> IPv4 record translation

GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"
# always IPv6 ready
BUILD_DEFS+=	USE_INET6

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/totd
	${INSTALL_DATA} ${FILESDIR}/totd.conf.sample \
		${PREFIX}/share/examples/totd/totd.conf.sample

.include "../../mk/bsd.pkg.mk"
