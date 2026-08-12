# $NetBSD: Makefile,v 1.10 2026/08/12 08:04:35 taca Exp $

DISTNAME=	dmarc-srg-${GITHUB_RELEASE}
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=liuch/}
GITHUB_PROJECT=	dmarc-srg
GITHUB_TYPE=	tag
GITHUB_TAG=	v${GITHUB_RELEASE}
GITHUB_RELEASE=	2.3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/liuch/dmarc-srg
COMMENT=	Viewer and summary report generator for DMARC reports
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=${PHP_BASE_VERS}:../../databases/php-pdo_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=${PHP_BASE_VERS}:../../archivers/php-zip

PHP_VERSIONS_ACCEPTED=	82 83 84

USE_LANGUAGES=	# none
USE_TOOLS+=	pax
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
BUILD_DEFS+=	APACHE_GROUP

WEBBASE=	dmarc-srg
WEBDIR=		share/${PHP_PKG_PREFIX}/${WEBBASE}
EGDIR=		share/examples/${PHP_PKG_PREFIX}/${WEBBASE}

PKG_SYSCONFSUBDIR=	${WEBBASE}

INSTALLATION_DIRS+=	${EGDIR}
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR} ${REAL_ROOT_USER} ${APACHE_GROUP} 0750
CONF_FILES+=		${EGDIR}/conf.php ${PKG_SYSCONFDIR}/conf.php
CONF_FILES+=		${EGDIR}/vendor_config.php \
			${PKG_SYSCONFDIR}/vendor_config.php
PLIST_SUBST+=		EGDIR=${EGDIR} WEBDIR=${WEBDIR}
PRINT_PLIST_AWK+=	/^${EGDIR:S|/|\\/|g}/ \
			{ gsub(/${EGDIR:S|/|\\/|g}/, "$${EGDIR}") }
PRINT_PLIST_AWK+=	/^${WEBDIR:S|/|\\/|g}/ \
			{ gsub(/${WEBDIR:S|/|\\/|g}/, "$${WEBDIR}") }

FILES_SUBST+=		WEBDIR=${WEBDIR}

SUBST_CLASSES+=		files
SUBST_STAGE.files=	do-configure
SUBST_MESSAGE.files=	Fixing configuration files.
SUBST_FILES.files=	config/vendor_config.php init.php
SUBST_VARS.files+=	PKG_SYSCONFDIR

do-install:
	${MV} ${WRKSRC}/config/conf.sample.php ${WRKDIR}/conf.php
	${MV} ${WRKSRC}/config/vendor_config.php ${WRKDIR}
	cd ${WRKSRC} && ${FIND} . -type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/${WEBDIR}
	${INSTALL_DATA} ${WRKDIR}/conf.php ${WRKDIR}/vendor_config.php \
		${DESTDIR}${PREFIX}/${EGDIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
