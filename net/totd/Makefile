# $NetBSD: Makefile,v 1.6 2000/11/18 07:24:15 itojun Exp $
#

DISTNAME=	totd-1.1p4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	feico@pasta.cs.uit.no
HOMEPAGE=	http://www.vermicelli.pasta.cs.uit.no/ipv6/software.html

WRKSRC=         ${WRKDIR}/totd-1.1p4

GNU_CONFIGURE=	YES
# Does not regard USE_INET6 <- leave this line in for README-IPv6.html

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/totd.conf.sample ${PREFIX}/etc/totd.conf.sample

.include "../../mk/bsd.pkg.mk"
