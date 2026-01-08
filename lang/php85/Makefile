# $NetBSD: Makefile,v 1.1 2026/01/08 13:38:00 taca Exp $

#
# We can't omit PKGNAME here to handle PKG_OPTIONS.
#
PKGNAME=		${PHP_PKG_PREFIX}-${PHP_VERSION}
CATEGORIES=		lang

COMMENT=		PHP Hypertext Preprocessor version 8.5
LICENSE=		php

TEST_TARGET=		test

USE_TOOLS+=		autoconf gmake lex
LIBTOOL_OVERRIDE=	# empty

PHP_VERSIONS_ACCEPTED=	85

.include "Makefile.php"

CGIDIR=			${PREFIX}/libexec/cgi-bin

CONFIGURE_ENV+=		lt_cv_path_SED=${SED:Q}
MAKE_ENV+=		INSTALL_ROOT=${DESTDIR}

CONF_FILES=		${PHP_EGDIR}/php.ini-production ${PKG_SYSCONFDIR}/php.ini
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

INSTALLATION_DIRS+=	${CGIDIR} ${PHP_EXTENSION_DIR} ${PHP_EGDIR} \
			${PHP_SHAREDIR}

# Make sure modules can link correctly
.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	yes
.endif

# Darwin < 9 (Mac OS X < 10.5 "Leopard") doesn't have gethostuuid(2)
# and lacks the zone memory allocator
.if !empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
CFLAGS+=	-DSQLITE_ENABLE_LOCKING_STYLE=0 -DSQLITE_WITHOUT_ZONEMALLOC
.endif

post-patch:
	${CP} ${.CURDIR}/${PHP_PKGSRC_README} ${WRKDIR}/${PHP_PKGSRC_README:T}

pre-configure:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${CONFIGURE_ENV} autoconf -f

post-install:
	cd ${WRKSRC}; ${INSTALL_DATA} php.ini-development php.ini-production \
		${DESTDIR}${PREFIX}/${PHP_EGDIR}
	${INSTALL_DATA} ${WRKDIR}/${PHP_PKGSRC_README:T} \
		${DESTDIR}${PREFIX}/${PHP_SHAREDIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
