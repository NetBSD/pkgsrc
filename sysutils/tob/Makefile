# $NetBSD: Makefile,v 1.9 2006/03/11 10:07:50 ghen Exp $

DISTNAME=	tob-0.25
CATEGORIES=	sysutils
MASTER_SITES=	http://tinyplanet.ca/projects/tob/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tinyplanet.ca/projects/tob/
COMMENT=	General driver for making and maintaining backups


EGDIR=		${PREFIX}/share/examples/tob
CONF_FILES=	${EGDIR}/tob.rc ${PKG_SYSCONFDIR}/tob/tob.rc
CONF_FILES+=	${EGDIR}/example.exclude ${PKG_SYSCONFDIR}/tob/volumes/example.exclude
CONF_FILES+=	${EGDIR}/example.startdir ${PKG_SYSCONFDIR}/tob/volumes/example.startdir

INSTALLATION_DIRS=	man/man8 sbin

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	tob

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
