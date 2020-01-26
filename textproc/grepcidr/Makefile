# $NetBSD: Makefile,v 1.6 2020/01/26 17:32:14 rillig Exp $

DISTNAME=	grepcidr-2.97
DIST_SUBDIR=	grepcidr-2.97-20150828
CATEGORIES=	textproc
MASTER_SITES=	http://www.taugh.com/grepcidr-2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.taugh.com/grepcidr-2/
COMMENT=	Filter IP addresses matching IPv4 or IPv6 CIDR specification
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/grepcidr \
		${DESTDIR}${PREFIX}/bin/grepcidr
	${INSTALL_MAN} ${WRKSRC}/grepcidr.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/grepcidr.1

.include "../../mk/bsd.pkg.mk"
