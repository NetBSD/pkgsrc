# $NetBSD: Makefile,v 1.87.8.1 2012/05/16 12:50:45 tron Exp $

PKGNAME=		php-${PHP_BASE_VERS}
PKGREVISION=		5
CATEGORIES=		lang

HOMEPAGE=		http://www.php.net/
COMMENT=		PHP Hypertext Preprocessor version 5
LICENSE=		php

TEST_TARGET=		test
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake lex pkg-config
LIBTOOL_OVERRIDE=	# empty

PKG_OPTIONS_REQUIRED_GROUPS+=	sapi
PKG_OPTIONS_GROUP.sapi=	cgi fastcgi
PKG_SUGGESTED_OPTIONS+=	cgi

.include "Makefile.php"

.if !empty(PKG_OPTIONS:Mcgi)
CONFIGURE_ARGS+=	--enable-discard-path
CONFIGURE_ARGS+=	--enable-force-cgi-redirect
.endif

.if !empty(PKG_OPTIONS:Mfastcgi)
CONFIGURE_ARGS+=	--enable-fastcgi
.endif

CGIDIR=			${PREFIX}/libexec/cgi-bin
EGDIR=			${PREFIX}/share/examples/php
MESSAGE_SUBST+=		CGIDIR=${CGIDIR:Q}

CONFIGURE_ENV+=		lt_cv_path_SED=${SED:Q}
MAKE_ENV+=		INSTALL_ROOT=${DESTDIR:Q}

CONF_FILES=		${EGDIR}/php.ini-recommended ${PKG_SYSCONFDIR}/php.ini
OWN_DIRS=		${PREFIX}/${PHP_EXTENSION_DIR}

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing common paths.
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	configure php.ini-dist php.ini-recommended
SUBST_SED.path=		-e 's,@CGIDIR@,${CGIDIR},g'
SUBST_SED.path+=	-e 's,@PREFIX@,${PREFIX},g'

INSTALLATION_DIRS+=	${CGIDIR}

# Make sure modules can link correctly
.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	yes
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cli/php \
		${DESTDIR:Q}${PREFIX:Q}/bin/php
	${INSTALL_DATA} ${WRKSRC}/sapi/cli/php.1 \
		${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}/man1/php.1
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cgi/php-cgi \
		${DESTDIR:Q}${CGIDIR:Q}/php
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${EGDIR:Q}
	cd ${WRKSRC}; ${INSTALL_DATA} php.ini-dist php.ini-recommended \
		${DESTDIR:Q}${EGDIR:Q}
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${PREFIX:Q}/share/php
	${INSTALL_DATA} ${WRKSRC}/php.gif ${DESTDIR:Q}${PREFIX:Q}/share/php

.include "../../mk/bsd.pkg.mk"
