# $NetBSD: Makefile,v 1.8 2001/02/17 18:19:47 wiz Exp $
#

DISTNAME=	totd-1.1p5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/
EXTRACT_SUFX=	.tgz

MAINTAINER=	feico@pasta.cs.uit.no
HOMEPAGE=	http://www.vermicelli.pasta.cs.uit.no/ipv6/software.html
COMMENT=	DNS proxy that supports IPv6 <==> IPv4 record translation

WRKSRC=         ${WRKDIR}/totd-1.1p5

GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"
# always IPv6 ready
BUILD_DEFS+=	USE_INET6

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/totd.conf.sample ${PREFIX}/etc/totd.conf.sample

.include "../../mk/bsd.pkg.mk"
