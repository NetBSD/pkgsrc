# $NetBSD: Makefile,v 1.4 2003/01/18 12:10:30 wiz Exp $
#

DISTNAME=	rootprobe-20030115
PKGNAME=	rootprobe-200301
WRKSRC=		${WRKDIR}/rootprobe
CATEGORIES=	net
MASTER_SITES=	http://mawi.wide.ad.jp/mawi/dnsprobe/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mawi.wide.ad.jp/mawi/dnsprobe/
COMMENT=	root DNS server performance analaysis

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rootprobe ${PREFIX}/bin
	(cd ${PREFIX}/bin; ${LN} rootprobe cctldprobe)

.include "../../mk/bsd.pkg.mk"
