# $NetBSD: Makefile,v 1.1 2015/11/24 11:38:28 wiz Exp $

DISTNAME=	baikal-regular-0.2.7
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/regular-//}
CATEGORIES=	net
MASTER_SITES=	http://baikal-server.com/get/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://baikal-server.com/
COMMENT=	Lightweight CalDAV+CardDAV server
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-pdo>=5.3.1:../../databases/php-pdo
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_sqlite>=5.3.1:../../databases/php-pdo_sqlite
DEPENDS+=	${PHP_PKG_PREFIX}-dom>=5.3.1:../../textproc/php-dom

WRKSRC=		${WRKDIR}/baikal-regular

USE_LANGUAGES=	# none
NO_BUILD=	yes

USE_TOOLS+=	pax

BUILD_DEFS+=	APACHE_GROUP APACHE_USER

BAIKALDIR=		share/baikal
INSTALLATION_DIRS=	${BAIKDALDIR}

CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/bin/vobjectvalidate.php
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/dav/bin/googlecode_upload.py
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/dav/bin/migrateto17.php
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/dav/bin/naturalselection.py
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/vobject/bin/bench.php
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/vobject/bin/generateicalendardata.php
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/vobject/bin/vobjectvalidate.php

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		BAIKALDIR=${BAIKALDIR}

do-install:
	${RM} -f ${WRKSRC}/*orig
	${RM} -f ${WRKSRC}/*/*/*/*/*orig
	cd ${WRKSRC} && pax -rw -pmp * \
		${DESTDIR}${PREFIX}/${BAIKALDIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
