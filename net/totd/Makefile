# $NetBSD: Makefile,v 1.4 2000/04/03 06:33:50 itojun Exp $
#

DISTNAME=	totd-1.1p4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	feico@pasta.cs.uit.no
HOMEPAGE=	http://www.vermicelli.cs.uit.no/ipv6/software.html

WRKSRC=         ${WRKDIR}/totd-1.1p4

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/totd.conf.sample ${PREFIX}/etc/totd.conf.sample

.include "../../mk/bsd.pkg.mk"
