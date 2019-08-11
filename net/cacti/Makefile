# $NetBSD: Makefile,v 1.41 2019/08/11 13:22:07 wiz Exp $

DISTNAME=	cacti-1.2.3
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://www.cacti.net/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cacti.net/
COMMENT=	Web frontend to rrdtool for monitoring systems and services
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		# none
USE_TOOLS+=		pax
NO_BUILD=		yes

#DEPENDS+=		${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd
DEPENDS+=		${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json
DEPENDS+=		${PHP_PKG_PREFIX}-zlib-[0-9]*:../../archivers/php-zlib
DEPENDS+=		${PHP_PKG_PREFIX}-mbstring-[0-9]*:../../converters/php-mbstring
DEPENDS+=		${PHP_PKG_PREFIX}-pdo_mysql-[0-9]*:../../databases/php-pdo_mysql
DEPENDS+=		${PHP_PKG_PREFIX}-snmp-[0-9]*:../../net/php-snmp
DEPENDS+=		${PHP_PKG_PREFIX}-sockets-[0-9]*:../../net/php-sockets
DEPENDS+=		${PHP_PKG_PREFIX}-gmp-[0-9]*:../../devel/php-gmp
DEPENDS+=		${PHP_PKG_PREFIX}-posix-[0-9]*:../../devel/php-posix
DEPENDS+=		${PHP_PKG_PREFIX}-ldap-[0-9]*:../../databases/php-ldap
DEPENDS+=		${PHP_PKG_PREFIX}-gettext-[0-9]*:../../devel/php-gettext
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

BUILD_DEFS+=		PKG_SYSCONFBASE VARBASE APACHE_GROUP
PKG_SYSCONFSUBDIR?=	httpd
EGDIR=			${PREFIX}/share/examples/cacti
CONF_FILES+=		${EGDIR}/httpd-cacti.conf ${PKG_SYSCONFDIR}/httpd-cacti.conf
CONF_FILES+=		${EGDIR}/config.php ${CACTIDIR}/include/config.php
CACTIDIR=		${PREFIX}/share/cacti
CACTI_LOGDIR?=		${VARBASE}/log/cacti
CACTI_RRADIR?=		${VARBASE}/db/cacti-rra

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php[^ ]*
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	cli/*.php

REPLACE_PERL+=		scripts/*.pl

MESSAGE_SUBST+=		CACTIDIR=${CACTIDIR}
MESSAGE_SUBST+=		CACTI_USER=${CACTI_USER}
MESSAGE_SUBST+=		EGDIR=${EGDIR}
MESSAGE_SUBST+=		PREFIX=${PREFIX}
MESSAGE_SUBST+=		VARBASE=${VARBASE}
MESSAGE_SUBST+=		PKG_SYSCONFBASE=${PKG_SYSCONFBASE}
FILES_SUBST+=		CACTIDIR=${CACTIDIR}
FILES_SUBST+=		CACTI_GROUP=${CACTI_GROUP}
FILES_SUBST+=		CACTI_USER=${CACTI_USER}
FILES_SUBST+=		CACTI_LOGDIR=${CACTI_LOGDIR}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	${WRKDIR}/httpd-cacti.conf
SUBST_FILES.paths+=	${WRKDIR}/cacti-poller
SUBST_FILES.paths+=	poller_maintenance.php utilities.php
SUBST_FILES.paths+=	cli/install_cacti.php install/functions.php
SUBST_FILES.paths+=	include/global.php include/global_settings.php
SUBST_FILES.paths+=	lib/clog_webapi.php lib/installer.php lib/functions.php
SUBST_VARS.paths=	CACTIDIR PREFIX CACTI_USER CACTI_LOGDIR CACTI_RRADIR
SUBST_VARS.paths+=	PKG_PHP_MAJOR_VERS SH

SUBST_CLASSES+=		perl-xml
SUBST_STAGE.perl-xml=	pre-configure
SUBST_FILES.perl-xml=	resource/script_queries/*.xml
SUBST_SED.perl-xml=	-e 's,>perl,>${PERL5},'

SUBST_CLASSES+=		docs
SUBST_STAGE.docs=	pre-configure
SUBST_FILES.docs=	docs/*.html
SUBST_SED.docs=		-e 's,/var/www/html/cacti,${CACTIDIR},g'

OWN_DIRS_PERMS+=	${CACTI_LOGDIR} ${CACTI_USER} ${APACHE_GROUP} 775
OWN_DIRS_PERMS+=	${CACTIDIR}/cache ${CACTI_USER} ${APACHE_GROUP} 775
OWN_DIRS_PERMS+=	${CACTIDIR}/cache/boost ${CACTI_USER} ${APACHE_GROUP} 775
OWN_DIRS_PERMS+=	${CACTIDIR}/cache/mibcache ${CACTI_USER} ${APACHE_GROUP} 775
OWN_DIRS_PERMS+=	${CACTIDIR}/cache/realtime ${CACTI_USER} ${APACHE_GROUP} 775
OWN_DIRS_PERMS+=	${CACTIDIR}/cache/spikekill ${CACTI_USER} ${APACHE_GROUP} 775
OWN_DIRS_PERMS+=	${CACTIDIR}/resource/snmp_queries ${CACTI_USER} ${APACHE_GROUP} 775
OWN_DIRS_PERMS+=	${CACTIDIR}/resource/script_server ${CACTI_USER} ${APACHE_GROUP} 775
OWN_DIRS_PERMS+=	${CACTIDIR}/resource/script_queries ${CACTI_USER} ${APACHE_GROUP} 775
OWN_DIRS_PERMS+=	${CACTIDIR}/scripts ${CACTI_USER} ${APACHE_GROUP} 775
OWN_DIRS_PERMS+=	${CACTI_RRADIR} ${CACTI_USER} ${APACHE_GROUP} 775
REQD_FILES_PERMS+=	${CACTIDIR}/log/.htaccess ${CACTI_LOGDIR}/.htaccess \
			${CACTI_USER} ${CACTI_GROUP} 644
REQD_FILES_PERMS+=	${CACTIDIR}/rra/.htaccess ${CACTI_RRADIR}/.htaccess \
			${CACTI_USER} ${CACTI_GROUP} 644

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	share/examples/cacti
INSTALLATION_DIRS+=	share/cacti

PLIST_VARS+=	localmemory
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux" || \
    ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS"
PLIST.localmemory=	yes
.endif

post-extract:
	${CP} ${FILESDIR}/httpd-cacti.conf ${WRKDIR}/
	${CP} ${FILESDIR}/cacti-poller ${WRKDIR}/
	${CP} ${FILESDIR}/freebsd_memory.pl ${WRKSRC}/scripts/
	${CP} ${FILESDIR}/netbsd_memory.pl ${WRKSRC}/scripts/
	${CP} ${FILESDIR}/solaris_memory.pl ${WRKSRC}/scripts/
	${CHMOD} 644 ${WRKSRC}/rra/.htaccess
	cd ${WRKSRC}/scripts;					\
	if [ -f ${LOWER_OPSYS}_memory.pl ]; then		\
	  ${LN} -fs ${LOWER_OPSYS}_memory.pl local_memory.pl;	\
	fi

do-install:
	${INSTALL_DATA} ${WRKDIR}/httpd-cacti.conf \
		${DESTDIR}${EGDIR}/httpd-cacti.conf
	${INSTALL_DATA} ${WRKSRC}/include/config.php \
		${DESTDIR}${EGDIR}/config.php
	${FIND} ${WRKSRC} -type f -name '*.orig' -exec ${RM} -f {} \;
	cd ${WRKSRC} && ${PAX} -rw -s ',\./include/config\.php,,' \
		. ${DESTDIR}${CACTIDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/cacti-poller ${DESTDIR}${PREFIX}/bin

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
