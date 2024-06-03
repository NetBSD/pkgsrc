# $NetBSD: Makefile,v 1.1 2024/06/03 15:12:19 taca Exp $

DISTNAME=	dmarc-srg-${GITHUB_RELEASE}
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=liuch/}
GITHUB_TYPE=	tag
GITHUB_TAG=	v${GITHUB_RELEASE}
GITHUB_RELEASE=	2.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/liuch
COMMENT=	Viewer and summary report generator for DMARC reports
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=${PHP_BASE_VERS}:../../databases/php-pdo_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=${PHP_BASE_VERS}:../../archivers/php-zip

PHP_VERSIONS_ACCEPTED=	81 82 83

USE_LANGUAGES=	# none
USE_TOOLS+=	pax
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
BUILD_DEFS+=	APACHE_GROUP

WEBBASE=	dmarc-srg
WEBDIR=		share/${PHP_PKG_PREFIX}/${WEBBASE}
EGDIR=		share/examples/${PHP_PKG_PREFIX}/${WEBBASE}

INSTALLATION_DIRS+=	${WEBDIR}/config ${EGDIR}
CONF_FILES_PERMS+=	${EGDIR}/conf.php ${WEBDIR}/config/conf.php \
			${BINOWN} ${APACHE_GROUP} 0640
PLIST_SUBST+=		EGDIR=${EGDIR} WEBDIR=${WEBDIR}
PRINT_PLIST_AWK+=	/^${EGDIR:S|/|\\/|g}/ \
			{ gsub(/${EGDIR:S|/|\\/|g}/, "$${EGDIR}") }
PRINT_PLIST_AWK+=	/^${WEBDIR:S|/|\\/|g}/ \
			{ gsub(/${WEBDIR:S|/|\\/|g}/, "$${WEBDIR}") }

pre-configure:
	${MV} ${WRKSRC}/config/conf.sample.php ${WRKDIR}

do-install:
	cd ${WRKSRC} && ${FIND} . -type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/${WEBDIR}
	${INSTALL_DATA} ${WRKDIR}/conf.sample.php \
		${DESTDIR}${PREFIX}/${EGDIR}/conf.php

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
