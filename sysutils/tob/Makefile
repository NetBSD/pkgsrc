# $NetBSD: Makefile,v 1.4 2005/06/17 03:50:36 jlam Exp $

DISTNAME=	tob-0.25
CATEGORIES=	sysutils
MASTER_SITES=	http://tinyplanet.ca/projects/tob/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tinyplanet.ca/projects/tob/
COMMENT=	General driver for making and maintaining backups

USE_PKGINSTALL=	yes

EGDIR=		${PREFIX}/share/examples/tob
CONF_FILES=	${EGDIR}/tob.rc ${PKG_SYSCONFDIR}/tob/tob.rc
SUPPORT_FILES=	${EGDIR}/example.exclude ${PKG_SYSCONFDIR}/tob/volumes/example.exclude
SUPPORT_FILES+=	${EGDIR}/example.startdir ${PKG_SYSCONFDIR}/tob/volumes/example.startdir

INSTALLATION_DIRS=	man/man8 sbin

do-build:
	for f in tob tob.rc; do						\
		${MV} ${WRKSRC}/$$f ${WRKSRC}/$$f-pre &&		\
		${SED} -e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g' 	\
			${WRKSRC}/$$f-pre > ${WRKSRC}/$$f;		\
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tob ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tob.8 ${PREFIX}/man/man8/
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/tob
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/tob/volumes
	${INSTALL_DATA_DIR} /var/tob
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/tob.rc ${EGDIR}/tob.rc
	${INSTALL_DATA} ${WRKSRC}/example.exclude ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/example.startdir ${EGDIR}

.include "../../mk/bsd.pkg.mk"
