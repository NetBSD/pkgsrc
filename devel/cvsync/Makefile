# $NetBSD: Makefile,v 1.20 2003/04/09 02:43:59 gehenna Exp $
#

DISTNAME=	cvsync-0.19.1
CATEGORIES=	devel
MASTER_SITES=	http://www.daemon-systems.org/cvsync/

MAINTAINER=	gehenna@NetBSD.ORG
HOMEPAGE=	http://www.daemon-systems.org/cvsync/
COMMENT=	portable incremental cvs repository syncer

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
USE_GMAKE=	YES

MAKE_ENV+=	PTHREAD_TYPE=${PTHREAD_TYPE}

EGDIR=		${PREFIX}/share/examples/cvsync
CONF_FILES+=	${EGDIR}/cvsync.conf ${PKG_SYSCONFDIR}/cvsync.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsync.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cvsyncd.conf ${EGDIR}

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
