# $NetBSD: Makefile,v 1.2 2010/03/21 17:10:01 jdolecek Exp $

PKGREVISION=		1
CATEGORIES=		lang
HOMEPAGE=		http://www.php.net/
COMMENT=		PHP Hypertext Preprocessor version 5

TEST_TARGET=		test
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake lex pkg-config
LIBTOOL_OVERRIDE=	# empty

.include "Makefile.php"

CGIDIR=			${PREFIX}/libexec/cgi-bin
EGDIR=			${PREFIX}/share/examples/php
MESSAGE_SUBST+=		CGIDIR=${CGIDIR:Q}

CONFIGURE_ENV+=		lt_cv_path_SED=${SED:Q}
MAKE_ENV+=		INSTALL_ROOT=${DESTDIR:Q}

CONF_FILES=		${EGDIR}/php.ini-production ${PKG_SYSCONFDIR}/php.ini
OWN_DIRS=		${PREFIX}/${PHP_EXTENSION_DIR}

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing common paths.
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	configure ext/phar/phar/phar.php
SUBST_FILES.path+=	php.ini-development php.ini-production run-tests.php
SUBST_SED.path=		-e 's,@CGIDIR@,${CGIDIR},g'
SUBST_SED.path+=	-e 's,@PREFIX@,${PREFIX},g'

INSTALLATION_DIRS+=	${CGIDIR}

# Make sure modules can link correctly
.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	yes
.endif

post-extract:
	cd ${WRKSRC} && \
		${FIND} . -xdev -type f -name '*.orig' -exec ${RM} -f {} \;

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cli/php \
		${DESTDIR:Q}${PREFIX:Q}/bin/php
	${INSTALL_DATA} ${WRKSRC}/sapi/cli/php.1 \
		${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}/man1/php.1
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cgi/php-cgi \
		${DESTDIR:Q}${CGIDIR:Q}/php
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${EGDIR:Q}
	cd ${WRKSRC}; ${INSTALL_DATA} php.ini-development php.ini-production \
		${DESTDIR:Q}${EGDIR:Q}
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${PREFIX:Q}/share/php
	${INSTALL_DATA} ${WRKSRC}/php.gif ${DESTDIR:Q}${PREFIX:Q}/share/php

.include "../../mk/bsd.pkg.mk"
