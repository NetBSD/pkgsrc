# $NetBSD: Makefile,v 1.40 2023/10/16 13:02:26 hauke Exp $

DISTNAME=	phpPgAdmin-7.13.0
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/PgAdmin/pgadmin/}
PKGREVISION=	1
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_GITHUB:=phppgadmin/}
GITHUB_PROJECT=	phppgadmin
GITHUB_TAG=	REL_7-13-0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/phppgadmin/phppgadmin
COMMENT=	Set of PHP scripts to administer PostgreSQL over the WWW

DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=7.2.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=7.2.0:../../databases/php-pgsql

PHP_VERSIONS_INCOMPATIBLE=	56

MESSAGE_SUBST+=	EGDIR=${EGDIR}

NO_BUILD=	YES

PHPPGBASE=	${PREFIX}/share/phppgadmin

EGDIR=		${PREFIX}/share/examples/phppgadmin
DOCDIR=		${PREFIX}/share/doc/phppgadmin
CONF_FILES=	${EGDIR}/config.inc.php-dist ${PHPPGBASE}/conf/config.inc.php
DOC_FILES=	CREDITS DEVELOPERS FAQ HISTORY INSTALL LICENSE TODO \
		TRANSLATORS

do-configure:
	${SED} -e "s#/usr/bin/pg#${PREFIX}/bin/pg#" \
		${WRKSRC}/conf/config.inc.php-dist > \
			${WRKSRC}/conf/config.inc.php-dist.tmp
	${MV} ${WRKSRC}/conf/config.inc.php-dist.tmp \
		${WRKSRC}/conf/config.inc.php-dist
	${SED} -e "s#@PHPPGBASE@#${PHPPGBASE}#g" ${FILESDIR}/apache.conf-dist \
		> ${WRKDIR}/apache.conf

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PHPPGBASE}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}

	for d in $$(cd ${WRKSRC} && find . -type d); do \
	        ${INSTALL_DATA_DIR} ${DESTDIR}${PHPPGBASE}/$$d; \
	done

	${INSTALL_SCRIPT} ${WRKSRC}/*.php ${DESTDIR}${PHPPGBASE}
	cd ${WRKSRC}; \
	for f in $$(find . -name "*.php"); do \
		${INSTALL_SCRIPT} $$f ${DESTDIR}${PHPPGBASE}/$$f; \
	done
# data:
	cd ${WRKSRC}; \
	for f in $$(find . -name "*.sql" -o -name "*.txt" -o -name "*.css" -o -name "*.js" -o -name "*.png" -o -name "*.gif" -o -name "*.ico"); do \
		${INSTALL_DATA} $$f ${DESTDIR}${PHPPGBASE}/$$f; \
	done

	${INSTALL_DATA} ${WRKSRC}/conf/config.inc.php-dist ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/apache.conf ${DESTDIR}${EGDIR}

	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	for f in ${DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${DOCDIR}; \
	done

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
