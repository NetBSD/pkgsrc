# $NetBSD: Makefile,v 1.7 2003/07/21 17:11:13 martti Exp $
#

DISTNAME=	rootprobe-20030115
PKGNAME=	rootprobe-200301
WRKSRC=		${WRKDIR}/rootprobe
CATEGORIES=	net
MASTER_SITES=	http://mawi.wide.ad.jp/mawi/dnsprobe/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mawi.wide.ad.jp/mawi/dnsprobe/
COMMENT=	Root DNS server performance analaysis

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rootprobe ${PREFIX}/bin
	(cd ${PREFIX}/bin; ${LN} rootprobe cctldprobe)

.include "../../mk/bsd.pkg.mk"
