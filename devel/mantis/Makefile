# $NetBSD: Makefile,v 1.1.1.1 2004/11/08 19:05:33 adrianp Exp $

DISTNAME=	mantis-0.19.1
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mantisbt/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.mantisdb.org/
COMMENT=	PHP/MySQL/web based bugtracking system

DEPENDS+=	ap-php>=4.0.6:../../www/ap-php
DEPENDS+=	php-mysql>=4.0.6:../../databases/php-mysql

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
NO_BUILD=	YES

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.mantis
PKG_SUPPORTED_OPTIONS=	charts

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcharts)
DEPENDS+=	php-jpgraph-[0-9]*:../../graphics/php-jpgraph
.endif

BUILDLINK_DEPENDS.mysql-client+=	mysql-client>=3.23.2
PHP_VERSIONS_ACCEPTED=			4
MYSQL_VERSIONS_ACCEPTED=		30 40

M_DB_HOST?=	localhost
M_DB_USER?=	root
M_DB_PASS?=	
M_DB_DATABASE?=	bugtracker
M_DOMAIN?=	example.com
APACHE_USER?=	www

BUILD_DEFS+=	M_DB_HOST M_DB_USER M_DB_PASS M_DB_DATABASE M_DOMAIN APACHE_USER
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

MANTIS_HOME=	${PREFIX}/share/mantis
EGDIR=		${PREFIX}/share/examples/mantis
CONF_FILES+=	${EGDIR}/mantis.conf ${PKG_SYSCONFDIR}/mantis.conf
SPECIAL_PERMS=	${MANTIS_HOME}/config_inc.php ${APACHE_USER} ${SHAREGRP} 0400

SUBST_CLASSES=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	config_inc.php mantis.conf
SUBST_SED.conf=		-e "s|localhost|${M_DB_HOST}|g"	\
			-e "s|root|${M_DB_USER}|g" \
			-e "s|\"\"|\"${M_DB_PASS}\"|g" \
			-e "s|bugtracker|${M_DB_DATABASE}|g" \
			-e "s|example.com|${DOMAIN}|g" \
			-e "s|@MANTIS_HOME@|${MANTIS_HOME}|g"
SUBST_MESSAGE.conf=	"Fixing configuration files."

post-extract:
	@${CP} ${FILESDIR}/mantis.conf ${WRKSRC}
	@${CP} ${WRKSRC}/config_inc.php.sample ${WRKSRC}/config_inc.php

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mantis
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${MANTIS_HOME}
	${INSTALL_DATA_DIR} ${MANTIS_HOME}/admin
	${INSTALL_DATA_DIR} ${MANTIS_HOME}/admin/css
	${INSTALL_DATA_DIR} ${MANTIS_HOME}/admin/upgrades
	${INSTALL_DATA_DIR} ${MANTIS_HOME}/core
	${INSTALL_DATA_DIR} ${MANTIS_HOME}/core/adodb
	${INSTALL_DATA_DIR} ${MANTIS_HOME}/core/adodb/lang
	${INSTALL_DATA_DIR} ${MANTIS_HOME}/core/adodb/drivers
	${INSTALL_DATA_DIR} ${MANTIS_HOME}/core/adodb/datadict
	${INSTALL_DATA_DIR} ${MANTIS_HOME}/core/phpmailer
	${INSTALL_DATA_DIR} ${MANTIS_HOME}/core/phpmailer/language
	${INSTALL_DATA_DIR} ${MANTIS_HOME}/css
	${INSTALL_DATA_DIR} ${MANTIS_HOME}/graphs
	${INSTALL_DATA_DIR} ${MANTIS_HOME}/images
	${INSTALL_DATA_DIR} ${MANTIS_HOME}/javascript
	${INSTALL_DATA_DIR} ${MANTIS_HOME}/lang
	${INSTALL_DATA} ${WRKSRC}/doc/CUSTOMIZATION ${PREFIX}/share/doc/mantis
	${INSTALL_DATA} ${WRKSRC}/doc/INSTALL ${PREFIX}/share/doc/mantis
	${INSTALL_DATA} ${WRKSRC}/doc/README ${PREFIX}/share/doc/mantis
	${INSTALL_DATA} ${WRKSRC}/doc/UPGRADING ${PREFIX}/share/doc/mantis
	${INSTALL_DATA} ${WRKSRC}/*.php ${MANTIS_HOME}
	${INSTALL_DATA} ${WRKSRC}/admin/*.php ${MANTIS_HOME}/admin
	${INSTALL_DATA} ${WRKSRC}/admin/*.css ${MANTIS_HOME}/admin
	${INSTALL_DATA} ${WRKSRC}/admin/css/*.php ${MANTIS_HOME}/admin/css
	${INSTALL_DATA} ${WRKSRC}/admin/upgrades/*.php \
		${MANTIS_HOME}/admin/upgrades
	${INSTALL_DATA} ${WRKSRC}/core/*.php ${MANTIS_HOME}/core
	${INSTALL_DATA} ${WRKSRC}/core/phpmailer/*.php \
		${MANTIS_HOME}/core/phpmailer
	${INSTALL_DATA} ${WRKSRC}/core/phpmailer/language/*.php \
		${MANTIS_HOME}/core/phpmailer/language
	${INSTALL_DATA} ${WRKSRC}/core/adodb/*.php ${MANTIS_HOME}/core/adodb
	${INSTALL_DATA} ${WRKSRC}/core/adodb/*.htm ${MANTIS_HOME}/core/adodb
	${INSTALL_DATA} ${WRKSRC}/core/adodb/lang/*.php \
		${MANTIS_HOME}/core/adodb/lang
	${INSTALL_DATA} ${WRKSRC}/core/adodb/drivers/*.php \
		${MANTIS_HOME}/core/adodb/drivers
	${INSTALL_DATA} ${WRKSRC}/core/adodb/datadict/*.php \
		${MANTIS_HOME}/core/adodb/datadict
	${INSTALL_DATA} ${WRKSRC}/css/*.css ${MANTIS_HOME}/css
	${INSTALL_DATA} ${WRKSRC}/graphs/*.php ${MANTIS_HOME}/graphs
	${INSTALL_DATA} ${WRKSRC}/images/*.gif ${MANTIS_HOME}/images
	${INSTALL_DATA} ${WRKSRC}/images/*.png ${MANTIS_HOME}/images
	${INSTALL_DATA} ${WRKSRC}/javascript/*.js ${MANTIS_HOME}/javascript
	${INSTALL_DATA} ${WRKSRC}/lang/*.txt ${MANTIS_HOME}/lang
	${INSTALL_DATA} ${WRKSRC}/sql/*.sql ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/config_inc.php.sample ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/mantis_offline.php.sample ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/mantis.conf ${EGDIR}

.include "../../mk/mysql.buildlink3.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
