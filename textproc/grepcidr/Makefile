# $NetBSD: Makefile,v 1.3 2013/12/27 05:56:49 apb Exp $

DISTNAME=	grepcidr-2.95
PKREVISION=	1
DIST_SUBDIR=	grepcidr-2.95-20131220
CATEGORIES=	textproc
MASTER_SITES=	http://www.taugh.com/grepcidr-2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://www.taugh.com/grepcidr-2/
COMMENT=	Filter IP addresses matching IPv4 or IPv6 CIDR specification
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/grepcidr \
		${DESTDIR}${PREFIX}/bin/grepcidr
	${INSTALL_MAN} ${WRKSRC}/grepcidr.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/grepcidr.1

.include "../../mk/bsd.pkg.mk"
