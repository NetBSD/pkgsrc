# $NetBSD: Makefile,v 1.5 2003/06/02 01:17:45 jschauma Exp $
#

DISTNAME=	rootprobe-20030115
PKGNAME=	rootprobe-200301
WRKSRC=		${WRKDIR}/rootprobe
CATEGORIES=	net
MASTER_SITES=	http://mawi.wide.ad.jp/mawi/dnsprobe/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://mawi.wide.ad.jp/mawi/dnsprobe/
COMMENT=	root DNS server performance analaysis

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rootprobe ${PREFIX}/bin
	(cd ${PREFIX}/bin; ${LN} rootprobe cctldprobe)

.include "../../mk/bsd.pkg.mk"
