# $NetBSD: Makefile,v 1.9 2001/03/10 02:23:00 itojun Exp $
#

DISTNAME=	totd-1.1p5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/
EXTRACT_SUFX=	.tgz

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	totd-1.1p5-20010310a.diff.gz
PATCH_DIST_STRIP=	-p1

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
