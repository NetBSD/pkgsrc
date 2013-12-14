# $NetBSD: Makefile,v 1.1 2013/12/14 06:56:16 apb Exp $

DISTNAME=	grepcidr-2.9
CATEGORIES=	textproc
MASTER_SITES=	http://www.taugh.com/grepcidr-2/
DISTFILES=	grepcidr.c grepcidr.1 Makefile ChangeLog

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://www.taugh.com/grepcidr-2/
COMMENT=	Filter IP addresses matching IPv4 or IPv6 CIDR specification
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/grepcidr \
		${DESTDIR}${PREFIX}/bin/grepcidr
	${INSTALL_MAN} ${WRKSRC}/grepcidr.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/grepcidr.1

.include "../../mk/bsd.pkg.mk"
