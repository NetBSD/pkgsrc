# $NetBSD: Makefile,v 1.65 2004/06/20 16:44:44 gehenna Exp $
#

DISTNAME=	cvsync-0.24.16
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cvsync.org/pub/cvsync/

MAINTAINER=	gehenna@NetBSD.org
HOMEPAGE=	http://www.cvsync.org/
COMMENT=	Portable incremental cvs repository syncer

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
USE_GNU_TOOLS+=	make
INSTALLATION_DIRS=	bin man/man1

MAKE_ENV+=	PTHREAD_TYPE=${PTHREAD_TYPE}
MAKE_ENV+=	PTHREAD_PREFIX=${BUILDLINK_PREFIX.pthread}

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
