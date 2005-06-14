# $NetBSD: Makefile,v 1.7 2005/06/14 11:25:09 adrianp Exp $

DISTNAME=	jpgraph-1.18
PKGNAME=	php-${DISTNAME}
CATEGORIES=	graphics www
MASTER_SITES=	http://members.chello.se/jpgraph/jpgdownloads/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE= 	http://www.aditus.nu/jpgraph/index.php
COMMENT=	Object Oriented class library for PHP

DEPENDS+=	php-gd>=4.3.1:../../graphics/php-gd

NO_CONFIGURE=	YES
NO_BUILD=	YES

EXDIR=		${PREFIX}/share/examples/php-jpgraph
PJDIR=		${PREFIX}/share/php-jpgraph
PJCONFFILE=	${PKG_SYSCONFDIR}/jpg-config.inc
CONF_FILES=     ${EXDIR}/jpg-config.inc ${PKG_SYSCONFDIR}/jpg-config.inc

USE_PKGINSTALL=         YES
PKG_SYSCONFSUBDIR?=     php-jpgraph

MESSAGE_SUBST+=	PJCONFFILE=${PJCONFFILE} PJDIR=${PJDIR} EXDIR=${EXDIR}

do-install:
	${INSTALL_DATA_DIR} ${EXDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/php-jpgraph
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/php-jpgraph
	${INSTALL_DATA_DIR} ${PJDIR}

	${INSTALL_SCRIPT} ${WRKSRC}/src/Examples/*.php ${EXDIR}
	${INSTALL_DATA} ${WRKSRC}/src/Examples/*.png ${EXDIR}
	${INSTALL_DATA} ${WRKSRC}/src/Examples/*.gif ${EXDIR}
	${INSTALL_DATA} ${WRKSRC}/src/Examples/*.jpg ${EXDIR}

	${RM} -f ${PJDIR}/jpg-config.inc

	${INSTALL_SCRIPT} ${WRKSRC}/src/*.php ${PJDIR}
	${INSTALL_DATA} ${WRKSRC}/src/*.inc ${PJDIR}
	${INSTALL_DATA} ${WRKSRC}/src/*.dat ${PJDIR}

	${MV} -f ${PJDIR}/jpg-config.inc ${EXDIR}
	${LN} -sf ${PJCONFFILE} ${PJDIR}/jpg-config.inc

	for f in README QPL.txt; do \
		${INSTALL_DATA} ${WRKSRC}/$$f \
			${PREFIX}/share/doc/php-jpgraph; \
	done
	cd ${WRKSRC}/docs && ${PAX} -rw . ${PREFIX}/share/doc/html/php-jpgraph
	${FIND} ${PREFIX}/share/doc/html/php-jpgraph -type d | ${XARGS} \
		${CHMOD} ${PKGDIRMODE}

.include "../../mk/bsd.pkg.mk"
