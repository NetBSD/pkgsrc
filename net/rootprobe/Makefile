# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 18:56:49 jlam Exp $
#

DISTNAME=	rootprobe
PKGNAME=	rootprobe-200204
CATEGORIES=	net
MASTER_SITES=	http://mawi.wide.ad.jp/mawi/dnsprobe/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mawi.wide.ad.jp/mawi/dnsprobe/
COMMENT=	root DNS server performance analaysis

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rootprobe ${PREFIX}/bin
	(cd ${PREFIX}/bin; ${LN} rootprobe cctldprobe)

.include "../../mk/bsd.pkg.mk"
