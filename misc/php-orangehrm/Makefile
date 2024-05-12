# $NetBSD: Makefile,v 1.14 2024/05/12 14:36:45 taca Exp $
#

DISTNAME=	orangehrm-4.10.1
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=orangehrm/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.orangehrm.com/
COMMENT=	Open source Human Resource Management (HRM) solution
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=5.2.0:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=5.2.0:../../databases/php-pdo_mysql

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
