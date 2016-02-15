# $NetBSD: Makefile,v 1.2 2016/02/15 23:28:22 wiz Exp $

DISTNAME=	baikal-0.3.1
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=fruux/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
GITHUB_PROJECT=	baikal
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://baikal-server.com/
COMMENT=	Lightweight CalDAV+CardDAV server
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-pdo>=5.3.1:../../databases/php-pdo
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_sqlite>=5.3.1:../../databases/php-pdo_sqlite
DEPENDS+=	${PHP_PKG_PREFIX}-dom>=5.3.1:../../textproc/php-dom

WRKSRC=		${WRKDIR}/baikal

USE_LANGUAGES=	# none
NO_BUILD=	yes

USE_TOOLS+=	pax

BUILD_DEFS+=	APACHE_GROUP APACHE_USER

BAIKALDIR=		share/baikal
INSTALLATION_DIRS=	${BAIKDALDIR}

# TODO:
# The directory "Specific" should probably be handled as configuration

CHECK_INTERPRETER_SKIP+=	share/baikal/Core/Frameworks/BaikalAdmin/Resources/GlyphiconsPro/generate-sprite.php
CHECK_INTERPRETER_SKIP+=	share/baikal/Core/Resources/Web/BaikalAdmin/GlyphiconsPro/generate-sprite.php
CHECK_INTERPRETER_SKIP+=	share/baikal/html/res/core/BaikalAdmin/GlyphiconsPro/generate-sprite.php
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/bin/generate_vcards
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/bin/naturalselection
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/bin/vobject
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/bin/vobjectvalidate.php
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/dav/bin/build.php
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/dav/bin/googlecode_upload.py
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/dav/bin/migrateto17.php
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/dav/bin/migrateto20.php
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/dav/bin/migrateto21.php
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/dav/bin/migrateto30.php
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/dav/bin/naturalselection
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/dav/bin/naturalselection.py
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/event/examples/promise.php
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/event/examples/tail.php
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/vobject/bin/bench.php
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/vobject/bin/fetch_windows_zones.php
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/vobject/bin/generate_vcards
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/vobject/bin/generateicalendardata.php
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/vobject/bin/mergeduplicates.php
CHECK_INTERPRETER_SKIP+=	share/baikal/vendor/sabre/vobject/bin/vobject
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
