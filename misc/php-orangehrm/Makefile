# $NetBSD: Makefile,v 1.1.1.1.4.1 2012/05/11 14:45:51 tron Exp $
#

DISTNAME=	orangehrm-2.7
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=orangehrm/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.orangehrm.com/
COMMENT=	Open source Human Resource Management (HRM) solution
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=5.2.0:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=5.2.0:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=5.2.0:../../databases/php-pdo_mysql

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
	cd ${WRKSRC} && pax -rw -pmp * \
		${DESTDIR}${PREFIX}/${OHRDIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
