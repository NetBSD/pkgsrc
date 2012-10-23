# $NetBSD: Makefile,v 1.14 2012/10/23 17:19:05 asau Exp $
#

DISTNAME=	rootprobe-20030115
PKGNAME=	rootprobe-200301
CATEGORIES=	net
MASTER_SITES=	http://mawi.wide.ad.jp/mawi/dnsprobe/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mawi.wide.ad.jp/mawi/dnsprobe/
COMMENT=	Root DNS server performance analysis

NOT_FOR_PLATFORM=	Interix-*-* # no <net/if.h> support

WRKSRC=		${WRKDIR}/rootprobe

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rootprobe ${DESTDIR}${PREFIX}/bin
	(cd ${DESTDIR}${PREFIX}/bin; ${LN} rootprobe cctldprobe)

.include "../../mk/bsd.pkg.mk"
