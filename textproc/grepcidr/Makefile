# $NetBSD: Makefile,v 1.2 2013/12/16 15:28:28 apb Exp $

DISTNAME=	grepcidr-2.95
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
