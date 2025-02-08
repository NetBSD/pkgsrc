# $NetBSD: Makefile,v 1.25 2025/02/08 03:43:10 taca Exp $

DISTNAME=	jpgraph-4.4.2
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics www
#MASTER_SITES=	https://jpgraph.net/download/download.php?p=57

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jpgraph.net/
COMMENT=	Object Oriented class library for PHP
LICENSE=	qpl-v1.0

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=${PHP_BASE_VERS}:../../graphics/php-gd

CONFLICTS=	php-jgraph-[0-9]*

USE_TOOLS+=	pax

NO_CONFIGURE=	YES
NO_BUILD=	YES

EXDIR=		${PREFIX}/share/examples/php-jpgraph
PJDIR=		${PREFIX}/share/php-jpgraph

PKG_SYSCONFSUBDIR?=	php-jpgraph

MESSAGE_SUBST+=	PJCONFFILE=${PJCONFFILE} PJDIR=${PJDIR} EXDIR=${EXDIR}

PHP_VERSIONS_ACCEPTED=	82 81 74 56

INSTALLATION_DIRS+=	${EXDIR} ${PJDIR} share/doc/php-jpgraph/html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/Examples/*.php ${DESTDIR}${EXDIR}
	${INSTALL_DATA} ${WRKSRC}/src/Examples/*.png ${DESTDIR}${EXDIR}
	${INSTALL_DATA} ${WRKSRC}/src/Examples/*.gif ${DESTDIR}${EXDIR}
	${INSTALL_DATA} ${WRKSRC}/src/Examples/*.jpg ${DESTDIR}${EXDIR}

	${INSTALL_SCRIPT} ${WRKSRC}/src/*.php ${DESTDIR}${PJDIR}
	${INSTALL_DATA} ${WRKSRC}/src/*.dat ${DESTDIR}${PJDIR}
	cd ${WRKSRC}/src && pax -rw barcode flag_mapping fonts lang themes ${DESTDIR}${PJDIR}

	${INSTALL_DATA} ${WRKSRC}/src/README ${DESTDIR}${PREFIX}/share/doc/php-jpgraph
	cd ${WRKSRC}/docs && pax -rw . \
		${DESTDIR}${PREFIX}/share/doc/php-jpgraph/html
	${FIND} ${DESTDIR}${PREFIX}/share/doc/php-jpgraph/html -type d | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${PREFIX}/share/doc/php-jpgraph/html ${DESTDIR}${PJDIR} ${DESTDIR}${EXDIR} -type f | \
		${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
