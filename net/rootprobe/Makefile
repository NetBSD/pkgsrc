# $NetBSD: Makefile,v 1.11 2005/11/02 15:34:31 tv Exp $
#

DISTNAME=	rootprobe-20030115
PKGNAME=	rootprobe-200301
CATEGORIES=	net
MASTER_SITES=	http://mawi.wide.ad.jp/mawi/dnsprobe/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mawi.wide.ad.jp/mawi/dnsprobe/
COMMENT=	Root DNS server performance analysis

NOT_FOR_PLATFORM=	Interix-*-* # no <net/if.h> support

WRKSRC=		${WRKDIR}/rootprobe

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rootprobe ${PREFIX}/bin
	(cd ${PREFIX}/bin; ${LN} rootprobe cctldprobe)

.include "../../mk/bsd.pkg.mk"
