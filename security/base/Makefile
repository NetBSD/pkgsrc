# $NetBSD: Makefile,v 1.14 2007/06/30 13:47:38 joerg Exp $
#

DISTNAME=	base-1.3.6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=secureideas/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://secureideas.sourceforge.net/
COMMENT=	Analysis engine to process a database of security events

# adodb is only available for PHP4
PHP_VERSIONS_ACCEPTED=	4

DEPENDS+=	adodb>=1.2:../../databases/adodb
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=4.0.4:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-sockets>=4.0.4:../../net/php-sockets
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.0.4:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Log-[0-9]*:../../sysutils/pear-Log
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Numbers_Words-[0-9]*:../../math/pear-Numbers_Words
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Numbers_Roman-[0-9]*:../../math/pear-Numbers_Roman
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Image_Color-[0-9]*:../../graphics/pear-Image_Color
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Image_Graph-[0-9]*:../../graphics/pear-Image_Graph

NO_BUILD=	YES

.include "../../mk/bsd.prefs.mk"

DOC_FILES=	CHANGELOG CREDITS README README.mssql TODO UPGRADE base_faq.rtf
BASE_DIR=	${PREFIX}/share/base
EGDIR=		${PREFIX}/share/examples/base
MESSAGE_SUBST+= EGDIR=${EGDIR:Q} BASE_DIR=${BASE_DIR:Q}
PAX_DIRS=	admin help images includes languages scripts setup sql styles
WWW_USER?=	${APACHE_USER}
WWW_GROUP?=	${APACHE_GROUP}
BUILD_DEFS+=	WWW_USER WWW_GROUP
USE_TOOLS+=	perl:run
REPLACE_PERL+=	scripts/base_maintenance.pl

CONF_FILES=	${EGDIR}/base.conf ${PKG_SYSCONFDIR}/base.conf

CONF_FILES_PERMS=	${EGDIR}/base_conf.php ${BASE_DIR}/base_conf.php \
			${WWW_USER} ${WWW_GROUP} 0600

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	base.conf base_conf.php.dist
SUBST_SED.conf=		-e "s|@BASE_DIR@|${BASE_DIR}|g"
SUBST_SED.conf+=	-e "s|@DBTYPE@|${DBTYPE}|g"
SUBST_SED.conf+=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.conf=	Fixing configuration files.

.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/base.conf ${WRKSRC}/base.conf
	${FIND} ${WRKSRC} -name *.php | ${XARGS} ${CHMOD} ${SHAREMODE}

do-install:
	${INSTALL_DATA_DIR} ${BASE_DIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/base

	${INSTALL_DATA} ${WRKSRC}/base.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/base_conf.php.dist ${EGDIR}/base_conf.php
	${INSTALL_DATA} ${WRKSRC}/*.php ${BASE_DIR}

.	for f in ${DOC_FILES}
		${INSTALL_DATA} ${WRKSRC}/docs/${f:Q} ${PREFIX}/share/doc/base
.	endfor

.	for i in ${PAX_DIRS}
		cd ${WRKSRC}/${i:Q} && ${PAX} -rw . ${BASE_DIR}/${i:Q}
.	endfor

	${CHOWN} ${WWW_USER} ${BASE_DIR}

.include "../../mk/apachever.mk"
.include "../../lang/php/phpversion.mk"
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.0.4:../../www/ap-php
.include "../../mk/bsd.pkg.mk"
