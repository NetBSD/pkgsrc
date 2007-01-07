# $NetBSD: Makefile,v 1.4 2007/01/07 09:14:13 rillig Exp $
#

DISTNAME=		shc-3.7
CATEGORIES=		sysutils
MASTER_SITES=		http://www.datsi.fi.upm.es/~frosal/sources/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.datsi.fi.upm.es/~frosal/
COMMENT=		Shell script to C compiler

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/shc.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
