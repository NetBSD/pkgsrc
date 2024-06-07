# $NetBSD: Makefile,v 1.3 2024/06/07 13:57:24 taca Exp $

#
# We can't omit PKGNAME here to handle PKG_OPTIONS.
#
PKGNAME=		php-${PHP_VERSION:S/RC/rc/}

COMMENT=		PHP Hypertext Preprocessor version 8.3
LICENSE=		php

TEST_TARGET=		test

USE_TOOLS+=		autoconf gmake lex
LIBTOOL_OVERRIDE=	# empty
PHP_CHECK_INSTALLED=	No

PHP_VERSIONS_ACCEPTED=		83

.include "Makefile.php"

CGIDIR=			${PREFIX}/libexec/cgi-bin
EGDIR=			${PREFIX}/share/examples/php
MESSAGE_SUBST+=		CGIDIR=${CGIDIR}

CONFIGURE_ENV+=		lt_cv_path_SED=${SED:Q}
MAKE_ENV+=		INSTALL_ROOT=${DESTDIR}

CONF_FILES=		${EGDIR}/php.ini-production ${PKG_SYSCONFDIR}/php.ini
PLIST_SUBST+=		PHPEXTDIR="${PHP_EXTENSION_DIR}"

# taken from devel/pkgconf/Makefile
PKGCONFIG_PATHS=	${PREFIX}/lib/pkgconfig
PKGCONFIG_PATHS+=	${PREFIX}/share/pkgconfig
PKGCONFIG_PATHS+=	/usr/lib/pkgconfig

# At this point, PREFIX is not set yet.
.if ${LOCALBASE} != ${X11BASE}
PKGCONFIG_PATHS+=	${X11BASE}/lib/pkgconfig
.endif

PHP_PKGCONFIG_PATH=	${PKGCONFIG_PATHS:ts:}

REPLACE_PHP=		ext/phar/phar/phar.php run-tests.php

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing common paths.
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	build/php.m4
SUBST_FILES.path+=	php.ini-development php.ini-production
SUBST_FILES.path+=	sapi/cgi/Makefile.frag
SUBST_VARS.path=	CGIDIR
SUBST_VARS.path+=	PREFIX
SUBST_VARS.path+=	TOOLS_PATH.pkg-config PHP_PKGCONFIG_PATH

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

pre-configure:
	cd ${WRKSRC} && autoconf -f

post-install:
	cd ${WRKSRC}; ${INSTALL_DATA} php.ini-development php.ini-production \
		${DESTDIR}${EGDIR}

.include "../../lang/php/replace.mk"
.include "../../mk/bsd.pkg.mk"
