# $NetBSD: Makefile,v 1.5 2005/01/15 08:33:23 jmmv Exp $

DISTNAME=	jpgraph-1.16
PKGNAME=	php-${DISTNAME}
CATEGORIES=	graphics www
MASTER_SITES=	http://www.aditus.nu/jpgraph/downloads/

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE= 	http://www.aditus.nu/jpgraph/index.php
COMMENT=	Object Oriented class library for PHP

DEPENDS+=	php-gd>=4.3.0:../../graphics/php-gd

NO_CONFIGURE=	YES
NO_BUILD=	YES
NO_BUILDLINK=	YES

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

	for f in README QPL.txt IMPORTANT_DO_README; do \
		${INSTALL_DATA} ${WRKSRC}/$$f \
			${PREFIX}/share/doc/php-jpgraph; \
	done
	cd ${WRKSRC}/docs && ${PAX} -rw . ${PREFIX}/share/doc/html/php-jpgraph

.include "../../mk/bsd.pkg.mk"
