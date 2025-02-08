# $NetBSD: Makefile,v 1.15 2025/02/08 03:46:36 taca Exp $
#

DISTNAME=	orangehrm-4.10.1
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=orangehrm/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.orangehrm.com/
COMMENT=	Open source Human Resource Management (HRM) solution
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=${PHP_BASE_VERS}:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=${PHP_BASE_VERS}:../../databases/php-pdo_mysql

PHP_VERSIONS_ACCEPTED=	56 74

EXTRACT_USING=		bsdtar
USE_TOOLS+=		bash pax

NO_BUILD=	yes

OHRDIR=		share/orangehrm

INSTALLATION_DIRS+=	${OHRDIR}

BUILD_DEFS+=		APACHE_GROUP APACHE_USER
FILES_SUBST+=		WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
			OHRDIR=${OHRDIR}

REPLACE_BASH=	installer/cli_common_commands.sh installer/cli_install.sh \
		travis-config-files/seeddb.sh

CHECK_INTERPRETER_SKIP+=	share/orangehrm/symfony/*
CHECK_INTERPRETER_SKIP+=	share/orangehrm/upgrader/symfony

pre-install:
	${FIND} ${WRKSRC} -name "*.orig*" -exec ${RM} -f {} +

do-install:
	${RM} -f symfony/lib/vendor/google/apiclient-services/generator/run_tests.sh.orig
	${CHMOD} -R og-w ${WRKSRC}
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} +
	cd ${WRKSRC} && pax -rw -pmp * \
		${DESTDIR}${PREFIX}/${OHRDIR}

.include "../../lang/php/phpversion.mk"
.include "../../lang/php/json.mk"
.include "../../mk/bsd.pkg.mk"
