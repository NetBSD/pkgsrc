# $NetBSD: Makefile,v 1.2 1999/11/22 21:07:54 itojun Exp $
#

DISTNAME=	totd-1.1p1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	feico@pasta.cs.uit.no
HOMEPAGE=	http://www.vermicelli.cs.uit.no/ipv6/software.html

WRKSRC=         ${WRKDIR}/totd-1.1p1

BUILD_DEFS+=    USE_INET6

.include "../../mk/bsd.prefs.mk"

.if !(defined(USE_INET6) && ${USE_INET6} == YES)
BROKEN=		"this is designed for IPv6/v4 dual stack node"
.endif

GNU_CONFIGURE=	YES

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/totd.conf.sample ${PREFIX}/etc/totd.conf.sample

.include "../../mk/bsd.pkg.mk"
