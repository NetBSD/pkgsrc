# $NetBSD: Makefile,v 1.30 2020/11/20 15:51:24 otis Exp $

#
# We can't omit PKGNAME here to handle PKG_OPTIONS.
#
PKGNAME=		php-${PHP_VERSION:S/RC/rc/}
PKGREVISION=		2

COMMENT=		PHP Hypertext Preprocessor version 7.2
LICENSE=		php

TEST_TARGET=		test

USE_TOOLS+=		gmake lex pkg-config
LIBTOOL_OVERRIDE=	# empty
PHP_CHECK_INSTALLED=	No

PHP_VERSIONS_ACCEPTED=	72

.include "Makefile.php"

CGIDIR=			${PREFIX}/libexec/cgi-bin
EGDIR=			${PREFIX}/share/examples/php
MESSAGE_SUBST+=		CGIDIR=${CGIDIR}

CONFIGURE_ENV+=		lt_cv_path_SED=${SED:Q}
MAKE_ENV+=		INSTALL_ROOT=${DESTDIR}

CONF_FILES=		${EGDIR}/php.ini-production ${PKG_SYSCONFDIR}/php.ini
PLIST_SUBST+=		PHPEXTDIR="${PHP_EXTENSION_DIR}"

REPLACE_PHP=		ext/phar/phar/phar.php run-tests.php

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing common paths.
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	php.ini-development php.ini-production
SUBST_FILES.path+=	sapi/cgi/Makefile.frag
SUBST_VARS.path=	CGIDIR PREFIX

INSTALLATION_DIRS+=	${CGIDIR} ${PHP_EXTENSION_DIR} ${EGDIR} share/php

# Make sure modules can link correctly
.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	yes
.endif

# Darwin < 9 (Mac OS X < 10.5 "Leopard") doesn't have gethostuuid(2)
# and lacks the zone memory allocator
.if !empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
CFLAGS+=	-DSQLITE_ENABLE_LOCKING_STYLE=0 -DSQLITE_WITHOUT_ZONEMALLOC
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cli/php ${DESTDIR}${PREFIX}/bin/php
	${INSTALL_DATA} ${WRKSRC}/sapi/cli/php.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/php.1
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cgi/php-cgi ${DESTDIR}${CGIDIR}/php
	cd ${WRKSRC}; ${INSTALL_DATA} php.ini-development php.ini-production \
		${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/php.gif ${DESTDIR}${PREFIX}/share/php

.include "../../lang/php/replace.mk"
.include "../../mk/bsd.pkg.mk"
