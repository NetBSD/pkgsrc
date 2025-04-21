# $NetBSD: Makefile,v 1.16 2025/04/21 21:09:45 wiz Exp $

DISTNAME=	rootprobe-20030115
PKGNAME=	rootprobe-200301
CATEGORIES=	net
MASTER_SITES=	http://mawi.wide.ad.jp/mawi/dnsprobe/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mawi.wide.ad.jp/mawi/dnsprobe/
COMMENT=	Root DNS server performance analysis

WRKSRC=		${WRKDIR}/rootprobe

LDFLAGS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rootprobe ${DESTDIR}${PREFIX}/bin
	(cd ${DESTDIR}${PREFIX}/bin; ${LN} rootprobe cctldprobe)

.include "../../mk/bsd.pkg.mk"
