# $NetBSD: Makefile,v 1.40 2025/02/08 02:57:59 taca Exp $

#
# We can't omit PKGNAME here to handle PKG_OPTIONS.
#
PKGNAME=		${PHP_PKG_PREFIX}-${PHP_VERSION}
CATEGORIES=		lang

COMMENT=		PHP Hypertext Preprocessor version 5.6
LICENSE=		php

TEST_TARGET=		test

USE_TOOLS+=		autoconf269 gmake lex pkg-config
LIBTOOL_OVERRIDE=	# empty

PHP_VERSIONS_ACCEPTED=	56

CONFLICTS+=		php-[0-9]*
SUPERSEDES+=		php-[0-9]*

.include "Makefile.php"

CGIDIR=			${PREFIX}/libexec/cgi-bin
MESSAGE_SUBST+=		CGIDIR=${CGIDIR} PHP_VER=${PHP_VER}

CONFIGURE_ARGS+=	--enable-cgi
CONFIGURE_ENV+=		lt_cv_path_SED=${SED:Q}
MAKE_ENV+=		INSTALL_ROOT=${DESTDIR}

CONF_FILES=		${PHP_EGDIR}/php.ini-production \
			${PKG_SYSCONFDIR}/php.ini
PLIST_SUBST+=		PHPEXTDIR="${PHP_EXTENSION_DIR}"

REPLACE_PHP+=		ext/phar/phar/phar.php run-tests.php

INSTALLATION_DIRS+=	${CGIDIR} ${PHP_EXTENSION_DIR} ${PHP_EGDIR} \
			${PHP_SHAREDIR}

# Darwin < 9 (Mac OS X < 10.5 "Leopard") doesn't have gethostuuid(2)
# and lacks the zone memory allocator
.if !empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
CFLAGS+=	-DSQLITE_ENABLE_LOCKING_STYLE=0 -DSQLITE_WITHOUT_ZONEMALLOC
.endif

pre-configure:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${CONFIGURE_ENV} autoconf -f

post-install:
	cd ${WRKSRC}; ${INSTALL_DATA} php.ini-development php.ini-production \
		${DESTDIR}${PREFIX}/${PHP_EGDIR}
	${INSTALL_DATA} ${WRKSRC}/php.gif \
		${DESTDIR}${PREFIX}/${PHP_SHAREDIR}

.include "../../mk/bsd.pkg.mk"
