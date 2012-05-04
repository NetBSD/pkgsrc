# $NetBSD: Makefile,v 1.24.2.1 2012/05/04 08:39:30 spz Exp $

#
# We can't omit PKGNAME here to handle PKG_OPTIONS.
#
PKGNAME=		php-${PHP_BASE_VERS}
CATEGORIES=		lang

HOMEPAGE=		http://www.php.net/
COMMENT=		PHP Hypertext Preprocessor version 5
LICENSE=		php

TEST_TARGET=		test
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake lex pkg-config
LIBTOOL_OVERRIDE=	# empty

.include "Makefile.php"

CGIDIR=			${PREFIX}/libexec/cgi-bin
EGDIR=			${PREFIX}/share/examples/php
MESSAGE_SUBST+=		CGIDIR=${CGIDIR}

CONFIGURE_ENV+=		lt_cv_path_SED=${SED:Q}
MAKE_ENV+=		INSTALL_ROOT=${DESTDIR}

CONF_FILES=		${EGDIR}/php.ini-production ${PKG_SYSCONFDIR}/php.ini
OWN_DIRS=		${PREFIX}/${PHP_EXTENSION_DIR}

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing common paths.
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	configure ext/phar/phar/phar.php
SUBST_FILES.path+=	php.ini-development php.ini-production run-tests.php
SUBST_SED.path=		-e 's,@CGIDIR@,${CGIDIR},g'
SUBST_SED.path+=	-e 's,@PREFIX@,${PREFIX},g'

INSTALLATION_DIRS+=	${CGIDIR} ${EGDIR} share/php

# Make sure modules can link correctly
.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	yes
.endif

post-extract:
	cd ${WRKSRC} && \
		${FIND} . -xdev -type f -name '*.orig' -exec ${RM} -f {} \;

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cli/php ${DESTDIR}${PREFIX}/bin/php
	${INSTALL_DATA} ${WRKSRC}/sapi/cli/php.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/php.1
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cgi/php-cgi ${DESTDIR}${CGIDIR}/php
	cd ${WRKSRC}; ${INSTALL_DATA} php.ini-development php.ini-production \
		${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/php.gif ${DESTDIR}${PREFIX}/share/php

.include "../../mk/bsd.pkg.mk"
