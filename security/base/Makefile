# $NetBSD: Makefile,v 1.44 2018/08/22 09:46:17 wiz Exp $

DISTNAME=	base-1.4.3.1
PKGREVISION=	13
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=secureideas/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://secureideas.sourceforge.net/
COMMENT=	Analysis engine to process a database of security events

PKG_DESTDIR_SUPPORT=	destdir

PHP_VERSIONS_ACCEPTED=	56

.include "../../mk/apache.mk"
.include "../../lang/php/phpversion.mk"

DEPENDS+=	adodb>=4.96a:../../databases/adodb
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=4.0.4:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-sockets>=4.0.4:../../net/php-sockets
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.0.4:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Log-[0-9]*:../../sysutils/pear-Log
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Numbers_Words-[0-9]*:../../math/pear-Numbers_Words
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Numbers_Roman-[0-9]*:../../math/pear-Numbers_Roman
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Image_Color-[0-9]*:../../graphics/pear-Image_Color
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Image_Graph-[0-9]*:../../graphics/pear-Image_Graph
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail-[0-9]*:../../mail/pear-Mail
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail_Mime-[0-9]*:../../mail/pear-Mail_Mime
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.0.4:../../www/ap-php

NO_BUILD=	YES
#WRKSRC=		${WRKDIR}/base-php4

.include "../../mk/bsd.prefs.mk"

DOC_FILES=		CHANGELOG CREDITS README README.mssql TODO \
			UPGRADE base_faq.rtf INSTALL INSTALL.rtf \
			README.country_support README.graph_alert_data
BASE_DIR=		${PREFIX}/share/base
EGDIR=			${PREFIX}/share/examples/base
MESSAGE_SUBST+= 	EGDIR=${EGDIR:Q} BASE_DIR=${BASE_DIR:Q}
PAX_DIRS=		admin help images includes languages scripts setup \
			sql styles
WWW_USER?=		${APACHE_USER}
WWW_GROUP?=		${APACHE_GROUP}
USE_TOOLS+=		pax perl:run
REPLACE_PERL+=		scripts/base_maintenance.pl

PKG_GROUPS_VARS+=	WWW_GROUP
PKG_USERS_VARS+=	WWW_USER

CONF_FILES=		${EGDIR}/base.conf ${PKG_SYSCONFDIR}/base.conf

CONF_FILES_PERMS=	${EGDIR}/base_conf.php ${BASE_DIR}/base_conf.php \
			${WWW_USER} ${WWW_GROUP} 0600

BUILD_DEFS+=		APACHE_USER APACHE_GROUP

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	base.conf base_conf.php.dist
SUBST_SED.conf=		-e "s|@BASE_DIR@|${BASE_DIR}|g"
SUBST_SED.conf+=	-e "s|@DBTYPE@|${DBTYPE}|g"
SUBST_SED.conf+=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.conf=	Fixing configuration files.

INSTALLATION_DIRS=	${BASE_DIR} ${EGDIR} share/doc/base

.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/base.conf ${WRKSRC}/base.conf
	${FIND} ${WRKSRC} -name *.php | ${XARGS} ${CHMOD} ${SHAREMODE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/base.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/base_conf.php.dist ${DESTDIR}${EGDIR}/base_conf.php
	${INSTALL_DATA} ${WRKSRC}/*.php ${DESTDIR}${BASE_DIR}

.	for f in ${DOC_FILES}
		${INSTALL_DATA} ${WRKSRC}/docs/${f:Q} ${DESTDIR}${PREFIX}/share/doc/base
.	endfor

.	for i in ${PAX_DIRS}
		${INSTALL_DATA_DIR} ${DESTDIR}${BASE_DIR}/${i:Q}
		cd ${WRKSRC}/${i:Q} && pax -rw . ${DESTDIR}${BASE_DIR}/${i:Q}
.	endfor

	${CHOWN} ${WWW_USER} ${DESTDIR}${BASE_DIR}

.include "../../mk/bsd.pkg.mk"
