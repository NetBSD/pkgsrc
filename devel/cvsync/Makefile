# $NetBSD: Makefile,v 1.58 2004/01/22 08:24:28 grant Exp $
#

DISTNAME=	cvsync-0.24.13
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cvsync.org/pub/cvsync/

MAINTAINER=	gehenna@NetBSD.ORG
HOMEPAGE=	http://www.cvsync.org/
COMMENT=	Portable incremental cvs repository syncer

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
USE_GNU_TOOLS+=	make

MAKE_ENV+=	PTHREAD_TYPE=${PTHREAD_TYPE}

EGDIR=		${PREFIX}/share/examples/cvsync
CONF_FILES+=	${EGDIR}/cvsync.conf ${PKG_SYSCONFDIR}/cvsync.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsync.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsyncd-NetBSD.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsyncd-OpenBSD.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsyncd.conf ${EGDIR}

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
