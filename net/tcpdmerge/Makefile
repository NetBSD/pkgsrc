# $NetBSD: Makefile,v 1.12 2013/02/06 19:31:00 jperkin Exp $

DISTNAME=	tcpdmerge-1.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://phantom.nemoto.ecei.tohoku.ac.jp/~akiraka/tcpdmerge/
DISTFILES=	tcpdmerge.c 00README.TXT

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://phantom.nemoto.ecei.tohoku.ac.jp/~akiraka/tcpdmerge/
COMMENT=	Merge two tcpdump output files

USE_BSD_MAKEFILE=	yes

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS+=	bin

post-extract:
	cp ${FILESDIR}/Makefile ${WRKSRC}

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
