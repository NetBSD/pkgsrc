# $NetBSD: Makefile,v 1.2 2001/01/28 04:46:03 jtb Exp $

DISTNAME=	fortran-utils-1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	jtb@netbsd.org

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
WRKSRC=		${WRKDIR}/fortran-utils

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fsplit/fsplit ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fsplit/fsplit.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/fsplit/fsplit.cat1 ${PREFIX}/man/cat1
	${INSTALL_PROGRAM} ${WRKSRC}/fpr/fpr ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fpr/fpr.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/fpr/fpr.cat1 ${PREFIX}/man/cat1

.include "../../mk/bsd.pkg.mk"
