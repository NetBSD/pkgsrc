# $NetBSD: Makefile,v 1.1.1.1 2000/12/08 23:20:56 jtb Exp $

DISTNAME=	fortran-utils-1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	jtb@netbsd.org

WRKSRC=		${WRKDIR}/fortran-utils

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fsplit/fsplit ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fsplit/fsplit.1 ${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/fpr/fpr ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fpr/fpr.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
