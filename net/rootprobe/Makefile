# $NetBSD: Makefile,v 1.9 2004/02/21 07:31:31 snj Exp $
#

DISTNAME=	rootprobe-20030115
PKGNAME=	rootprobe-200301
CATEGORIES=	net
MASTER_SITES=	http://mawi.wide.ad.jp/mawi/dnsprobe/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mawi.wide.ad.jp/mawi/dnsprobe/
COMMENT=	Root DNS server performance analysis

WRKSRC=		${WRKDIR}/rootprobe

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rootprobe ${PREFIX}/bin
	(cd ${PREFIX}/bin; ${LN} rootprobe cctldprobe)

.include "../../mk/bsd.pkg.mk"
