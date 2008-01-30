# $NetBSD: Makefile,v 1.22 2008/01/30 10:07:34 tnn Exp $

DISTNAME=	phpPgAdmin-4.1.3
PKGNAME=	${DISTNAME:S/PgAdmin/pgadmin/}
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phppgadmin/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://phppgadmin.sourceforge.net/
COMMENT=	Set of PHP-scripts to administer PostgreSQL over the WWW

DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=4.2.0:../../databases/php-pgsql

PKG_DESTDIR_SUPPORT=	user-destdir

MESSAGE_SUBST+=	EGDIR=${EGDIR}

NO_BUILD=	YES

PHPPGBASE=	${PREFIX}/share/phppgadmin
PHPPGHIER=	conf help sql xloadtree \
		libraries/adodb/drivers libraries/adodb/lang \
		classes/database classes/plugins lang/recoded \
		images/themes/default themes/default

EGDIR=		${PREFIX}/share/examples/phppgadmin
DOCDIR=		${PREFIX}/share/doc/phppgadmin
CONF_FILES=	${EGDIR}/config.inc.php-dist ${PHPPGBASE}/conf/config.inc.php
DOC_FILES=	CREDITS DEVELOPERS FAQ HISTORY INSTALL LICENSE TODO \
		TRANSLATORS
REQD_DIRS+=	${PHPPGBASE} ${PHPPGBASE}/conf

do-configure:
	@${SED} -e "s#/usr/bin/pg#${PREFIX}/bin/pg#" \
		${WRKSRC}/conf/config.inc.php-dist > \
			${WRKSRC}/conf/config.inc.php-dist.tmp
	@${MV} ${WRKSRC}/conf/config.inc.php-dist.tmp \
		${WRKSRC}/conf/config.inc.php-dist
	@${SED} -e "s#@PHPPGBASE@#${PHPPGBASE}#g" ${FILESDIR}/apache.conf-dist \
		> ${WRKDIR}/apache.conf

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PHPPGBASE}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}

	for d in ${PHPPGHIER}; do \
	        ${INSTALL_DATA_DIR} ${DESTDIR}${PHPPGBASE}/$$d; \
	done

	${INSTALL_SCRIPT} ${WRKSRC}/*.* ${DESTDIR}${PHPPGBASE}
	${INSTALL_SCRIPT} ${WRKSRC}/classes/*.* ${DESTDIR}${PHPPGBASE}/classes
	${INSTALL_SCRIPT} ${WRKSRC}/classes/database/* \
		${DESTDIR}${PHPPGBASE}/classes/database
	${INSTALL_SCRIPT} ${WRKSRC}/help/* ${DESTDIR}${PHPPGBASE}/help
	${INSTALL_SCRIPT} ${WRKSRC}/sql/* ${DESTDIR}${PHPPGBASE}/sql
	${INSTALL_DATA} ${WRKSRC}/images/themes/default/*.png \
		${DESTDIR}${PHPPGBASE}/images/themes/default
	${INSTALL_SCRIPT} ${WRKSRC}/lang/*.* ${DESTDIR}${PHPPGBASE}/lang
	${INSTALL_SCRIPT} ${WRKSRC}/lang/recoded/*.* ${DESTDIR}${PHPPGBASE}/lang/recoded
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/*.php ${DESTDIR}${PHPPGBASE}/libraries
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/adodb/*.php \
		${DESTDIR}${PHPPGBASE}/libraries/adodb
	${INSTALL_DATA} ${WRKSRC}/libraries/adodb/*.txt \
		${DESTDIR}${PHPPGBASE}/libraries/adodb
	${INSTALL_SCRIPT} ${WRKSRC}/libraries/adodb/drivers/* \
		${DESTDIR}${PHPPGBASE}/libraries/adodb/drivers
	${INSTALL_DATA} ${WRKSRC}/themes/default/global.css \
		${DESTDIR}${PHPPGBASE}/themes/default
	${INSTALL_DATA} ${WRKSRC}/conf/config.inc.php-dist ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/apache.conf ${DESTDIR}${EGDIR}

	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	for f in ${DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${DOCDIR}; \
	done

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
