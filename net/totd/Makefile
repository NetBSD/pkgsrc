# $NetBSD: Makefile,v 1.5 2000/10/19 22:53:15 hubertf Exp $
#

DISTNAME=	totd-1.1p4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	feico@pasta.cs.uit.no
HOMEPAGE=	http://www.vermicelli.cs.uit.no/ipv6/software.html

WRKSRC=         ${WRKDIR}/totd-1.1p4

GNU_CONFIGURE=	YES
# Does not regard USE_INET6 <- leave this line in for README-IPv6.html

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/totd.conf.sample ${PREFIX}/etc/totd.conf.sample

.include "../../mk/bsd.pkg.mk"
