# $NetBSD: Makefile,v 1.62 2004/04/25 05:21:05 snj Exp $
#

DISTNAME=	cvsync-0.24.15
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cvsync.org/pub/cvsync/

MAINTAINER=	gehenna@NetBSD.ORG
HOMEPAGE=	http://www.cvsync.org/
COMMENT=	Portable incremental cvs repository syncer

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
USE_GNU_TOOLS+=	make

MAKE_ENV+=	PTHREAD_TYPE=${PTHREAD_TYPE}

EGDIR=		${PREFIX}/share/examples/cvsync
CONF_FILES+=	${EGDIR}/cvsync.conf ${PKG_SYSCONFDIR}/cvsync.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsync.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsyncd-FreeBSD.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsyncd-NetBSD.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsyncd-OpenBSD.conf ${EGDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
