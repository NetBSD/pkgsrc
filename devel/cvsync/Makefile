# $NetBSD: Makefile,v 1.4 2003/03/06 13:15:48 gehenna Exp $
#

DISTNAME=	cvsync-0.14.1
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.daemon-systems.org/cvsync/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gehenna@NetBSD.ORG
HOMEPAGE=	http://www.daemon-systems.org/cvsync/
COMMENT=	a portable incremental cvs repository syncer

WRKSRC=		${WRKDIR}/cvsync-0.14.1
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
