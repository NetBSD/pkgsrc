# $NetBSD: Makefile,v 1.1.1.1 2004/04/20 09:50:54 xtraeme Exp $
#

DISTNAME=	acid-0.9.6b23
CATEGORIES=	databases www
MASTER_SITES=	http://www.andrew.cmu.edu/~rdanyliw/snort/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.andrew.cmu.edu/~rdanyliw/snort/snortacid.html
COMMENT=	Database class library for PHP4

DEPENDS+=       ap-php>=4.0.4:../../www/ap-php4
DEPENDS+=	apache>=1.3:../../www/apache
DEPENDS+=	adodb>=1.2:../../wip/adodb
DEPENDS+=	php-jpgraph>=1.8:../../graphics/php-jpgraph
DEPENDS+=	php-gd>=4.0.4:../../graphics/php4-gd
DEPENDS+=	php-sockets>=4.0.4:../../net/php4-sockets

USE_BUILDLINK3=	YES
WRKSRC=		${WRKDIR}/acid

.include "../../mk/bsd.prefs.mk"

# This package will default to using MySQL.  If you want to use
# postgresql set USE_PGSQL=YES in /etc/mk.conf or pass it to
# make. ie. make install USE_PGSQL=YES
#
.if defined(USE_PGSQL) && ${USE_PGSQL} == YES
DEPENDS+=	php-pgsql>=4.0.4:../../databases/php4-pgsql
DBTYPE=		postgres
.else
DEPENDS+=	php-mysql>=4.0.4:../../databases/php4-mysql
DBTYPE=		mysql
.endif

BUILD_DEFS+=	USE_PGSQL

DOC_FILES=	CHANGELOG CREDITS README README.mssql TODO
ACID_DIR=	${PREFIX}/share/acid
EXDIR=		${PREFIX}/share/examples/acid
MESSAGE_SUBST+= EXDIR=${EXDIR} ACID_DIR=${ACID_DIR}

do-build:
	@${SED} -e 's#@ACID_DIR@#${ACID_DIR}#g' ${FILESDIR}/acid.conf \
		>${WRKDIR}/acid.conf

	@${CP} ${WRKSRC}/acid_conf.php ${WRKSRC}/acid_conf.php.orig

	@${SED} -e 's#@PREFIX@#${PREFIX}#g' \
			-e 's#@DBTYPE@#${DBTYPE}#g' \
			${WRKSRC}/acid_conf.php.orig >${WRKSRC}/acid_conf.php

do-install:
	${INSTALL_DATA_DIR} ${ACID_DIR}
	${INSTALL_DATA_DIR} ${EXDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/acid
	${INSTALL_SCRIPT} ${WRKSRC}/*.php ${ACID_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.inc ${ACID_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${ACID_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.sql ${ACID_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.css ${ACID_DIR}

	for FILE in ${DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$FILE ${PREFIX}/share/doc/acid; \
	done

	${INSTALL_DATA} ${WRKDIR}/acid.conf ${EXDIR}

.include "../../mk/bsd.pkg.mk"
