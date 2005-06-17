# $NetBSD: Makefile,v 1.2 2005/06/17 03:50:35 jlam Exp $
#

DISTNAME=		shc-3.7
CATEGORIES=		sysutils
MASTER_SITES=		http://www.datsi.fi.upm.es/~frosal/sources/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.datsi.fi.upm.es/~frosal/
COMMENT=		Shell script to C compiler

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/shc.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
