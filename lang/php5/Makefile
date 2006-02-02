# $NetBSD: Makefile,v 1.25 2006/02/02 20:31:17 rillig Exp $
#

PKGNAME=		php-${PHP_BASE_VERS}
PKGREVISION=		3
CATEGORIES=		lang

HOMEPAGE=		http://www.php.net/
COMMENT=		PHP Hypertext Preprocessor version 5

USE_TOOLS+=		gmake
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

CONF_FILES=		${EGDIR}/php.ini-recommended ${PKG_SYSCONFDIR}/php.ini
OWN_DIRS=		${PREFIX}/${PHP_EXTENSION_DIR}

# pear must be patched using post-install, it's extracted from binary .phar
# file during installation; this replaces former patches/patch-al
post-install:
	${SED} -e 's,\(-d output_buffering=1\) \(\$$INCDIR/pearcmd.php\),\1 -n \2,' ${PREFIX}/bin/pear > ${PREFIX}/bin/pear.new && \
		${MV} ${PREFIX}/bin/pear.new ${PREFIX}/bin/pear
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cli/php ${PREFIX}/bin/php
	${INSTALL_DATA} ${WRKSRC}/sapi/cli/php.1 ${PREFIX}/${PKGMANDIR}/man1/php.1
	${INSTALL_DATA_DIR} ${CGIDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cgi/php ${CGIDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} php.ini-dist php.ini-recommended ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/php
	${INSTALL_DATA} ${WRKSRC}/php.gif ${PREFIX}/share/php

.include "../../mk/bsd.pkg.mk"
