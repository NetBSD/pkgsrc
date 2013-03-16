# $NetBSD: Makefile,v 1.14 2013/03/16 07:21:22 obache Exp $
#

DISTNAME=		cacti-0.8.8a
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://www.cacti.net/downloads/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cacti.net/
COMMENT=		Frontend to rrdtool for monitoring systems and services
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		# none
USE_TOOLS+=		pax
NO_BUILD=		yes

DEPENDS+=		${PHP_PKG_PREFIX}-mysql-[0-9]*:../../databases/php-mysql
DEPENDS+=		${PHP_PKG_PREFIX}-snmp-[0-9]*:../../net/php-snmp
DEPENDS+=		${PHP_PKG_PREFIX}-sockets-[0-9]*:../../net/php-sockets
DEPENDS+=		${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}-[0-9]*:../../www/ap-php

.include "../../mk/bsd.prefs.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/apache.mk"

PKG_USERS=		${CACTI_USER}:${CACTI_GROUP}
PKG_GROUPS=		${CACTI_GROUP}
PKG_GECOS.${CACTI_USER}=	Cacti user
PKG_HOME.${CACTI_USER}=	${CACTIDIR}
PKG_SHELL.${CACTI_USER}=	${SH}
PKG_USERS_VARS+=	CACTI_USER
PKG_GROUPS_VARS+=	CACTI_GROUP

BUILD_DEFS+=		PKG_SYSCONFBASE
PKG_SYSCONFSUBDIR?=	httpd
EGDIR=			${PREFIX}/share/examples/cacti
CONF_FILES+=		${EGDIR}/httpd-cacti.conf ${PKG_SYSCONFDIR}/httpd-cacti.conf
CACTIDIR=		${PREFIX}/share/cacti
CACTI_LOGDIR?=		${CACTIDIR}/log
CACTI_RRADIR?=		${CACTIDIR}/rra

REPLACE_INTERPRETER+=   php
REPLACE.php.old=        .*php[^ ]*
REPLACE.php.new=        ${PREFIX}/bin/php
REPLACE_FILES.php=      cli/*.php

REPLACE_PERL+=         scripts/*.pl

MESSAGE_SUBST+=         CACTIDIR=${CACTIDIR}
MESSAGE_SUBST+=         CACTI_LOGDIR=${CACTI_LOGDIR}
MESSAGE_SUBST+=         CACTI_USER=${CACTI_USER}
MESSAGE_SUBST+=         EGDIR=${EGDIR}
MESSAGE_SUBST+=         PREFIX=${PREFIX}
MESSAGE_SUBST+=         PKG_SYSCONFBASE=${PKG_SYSCONFBASE}
FILES_SUBST+=		CACTIDIR=${CACTIDIR}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	${WRKDIR}/httpd-cacti.conf install/index.php
SUBST_FILES.paths+=	include/global.php include/global_settings.php
SUBST_VARS.paths=	CACTIDIR PREFIX CACTI_USER CACTI_LOGDIR CACTI_RRADIR
SUBST_VARS.paths+=	PKG_PHP_MAJOR_VERS

SUBST_CLASSES+=		docs
SUBST_STAGE.docs=	pre-configure
SUBST_FILES.docs=	docs/txt/manual.txt docs/html/*.html
SUBST_SED.docs=		-e 's,/var/www/html/cacti,${CACTIDIR},g'

OWN_DIRS_PERMS+=	${CACTI_LOGDIR} ${CACTI_USER} ${CACTI_GROUP} 755
OWN_DIRS_PERMS+=	${CACTI_RRADIR} ${CACTI_USER} ${CACTI_GROUP} 755
SPECIAL_PERMS+=		share/cacti/log/cacti.log ${CACTI_USER} ${CACTI_GROUP} 755

INSTALLATION_DIRS=      share/examples/cacti
INSTALLATION_DIRS+=	share/cacti

post-extract:
	${CP} ${FILESDIR}/httpd-cacti.conf ${WRKDIR}/
	${CP} ${FILESDIR}/freebsd_memory.pl ${WRKSRC}/scripts/
	${CP} ${FILESDIR}/netbsd_memory.pl ${WRKSRC}/scripts/
	${CP} ${FILESDIR}/solaris_memory.pl ${WRKSRC}/scripts/

do-install:
	${INSTALL_DATA} ${WRKDIR}/httpd-cacti.conf ${DESTDIR}${EGDIR}/httpd-cacti.conf
	${FIND} ${WRKSRC} -type f -name '*.orig' -exec ${RM} -f {} \;
	cd ${WRKSRC} && ${PAX} -wr * ${DESTDIR}${CACTIDIR}


.include "../../databases/rrdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
