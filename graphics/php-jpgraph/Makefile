# $NetBSD: Makefile,v 1.20 2012/10/06 14:11:14 asau Exp $

DISTNAME=	jpgraph-1.18
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	graphics www
MASTER_SITES=	http://members.chello.se/jpgraph/jpgdownloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jpgraph.net/
COMMENT=	Object Oriented class library for PHP

CONFLICTS=	php-jgraph-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=4.3.1:../../graphics/php-gd

USE_TOOLS+=	pax

NO_CONFIGURE=	YES
NO_BUILD=	YES

EXDIR=		${PREFIX}/share/examples/php-jpgraph
PJDIR=		${PREFIX}/share/php-jpgraph
PJCONFFILE=	${PKG_SYSCONFDIR}/jpg-config.inc
CONF_FILES=	${EXDIR}/jpg-config.inc ${PKG_SYSCONFDIR}/jpg-config.inc

PKG_SYSCONFSUBDIR?=	php-jpgraph

MESSAGE_SUBST+=	PJCONFFILE=${PJCONFFILE} PJDIR=${PJDIR} EXDIR=${EXDIR}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EXDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/php-jpgraph
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/php-jpgraph/html
	${INSTALL_DATA_DIR} ${DESTDIR}${PJDIR}

	${INSTALL_SCRIPT} ${WRKSRC}/src/Examples/*.php ${DESTDIR}${EXDIR}
	${INSTALL_DATA} ${WRKSRC}/src/Examples/*.png ${DESTDIR}${EXDIR}
	${INSTALL_DATA} ${WRKSRC}/src/Examples/*.gif ${DESTDIR}${EXDIR}
	${INSTALL_DATA} ${WRKSRC}/src/Examples/*.jpg ${DESTDIR}${EXDIR}

	${RM} -f ${DESTDIR}${PJDIR}/jpg-config.inc

	${INSTALL_SCRIPT} ${WRKSRC}/src/*.php ${DESTDIR}${PJDIR}
	${INSTALL_DATA} ${WRKSRC}/src/*.inc ${DESTDIR}${PJDIR}
	${INSTALL_DATA} ${WRKSRC}/src/*.dat ${DESTDIR}${PJDIR}

	${MV} -f ${DESTDIR}${PJDIR}/jpg-config.inc ${DESTDIR}${EXDIR}
	${LN} -sf ${PJCONFFILE} ${DESTDIR}${PJDIR}/jpg-config.inc

	for f in README QPL.txt; do \
		${INSTALL_DATA} ${WRKSRC}/$$f \
			${DESTDIR}${PREFIX}/share/doc/php-jpgraph; \
	done
	cd ${WRKSRC}/docs && pax -rw . \
		${DESTDIR}${PREFIX}/share/doc/php-jpgraph/html
	${FIND} ${DESTDIR}${PREFIX}/share/doc/php-jpgraph/html -type d | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
