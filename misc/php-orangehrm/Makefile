# $NetBSD: Makefile,v 1.10 2022/05/01 23:34:31 wiz Exp $
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

PHP_VERSIONS_ACCEPTED=	56 74 80

EXTRACT_USING=		bsdtar
USE_TOOLS+=		pax

NO_BUILD=	yes

OHRDIR=		share/orangehrm

INSTALLATION_DIRS+=	${OHRDIR}

BUILD_DEFS+=		APACHE_GROUP APACHE_USER
FILES_SUBST+=		WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
			OHRDIR=${OHRDIR}

CHECK_INTERPRETER_SKIP+=	share/orangehrm/symfony/lib/vendor/symfony/data/bin/symfony
CHECK_INTERPRETER_SKIP+=	share/orangehrm/symfony/lib/vendor/symfony/lib/plugins/sfDoctrinePlugin/test/functional/fixtures/symfony
CHECK_INTERPRETER_SKIP+=	share/orangehrm/symfony/lib/vendor/symfony/lib/task/generator/skeleton/project/symfony
CHECK_INTERPRETER_SKIP+=	share/orangehrm/symfony/symfony
CHECK_INTERPRETER_SKIP+=	share/orangehrm/upgrader/symfony

do-install:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} og-w {} \;
	cd ${WRKSRC} && pax -rw -pmp * \
		${DESTDIR}${PREFIX}/${OHRDIR}

.include "../../lang/php/phpversion.mk"
.include "../../lang/php/json.mk"
.include "../../mk/bsd.pkg.mk"
