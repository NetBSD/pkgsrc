# $NetBSD: Makefile,v 1.31 2006/05/07 09:29:35 jdolecek Exp $

PKGNAME=		php-${PHP_BASE_VERS}
#PKGREVISION=		# empty
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

# fetch pear PHAR explicitly; the PHP installation tries to wget it if it's not
# present; use DIST_SUBDIR, since the pear file is not versioned
DIST_SUBDIR=		${PKGNAME}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			install-pear-nozlib.phar

# do not checksum the pear file - it's not versioned and might (and
# very probably will) change over time
IGNOREFILES=		install-pear-nozlib.phar

SITES.install-pear-nozlib.phar =	http://pear.php.net/

post-extract:
	${CP} ${DISTDIR}/install-pear-nozlib.phar ${WRKSRC}/pear/

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cli/php ${PREFIX}/bin/php
	${INSTALL_DATA} ${WRKSRC}/sapi/cli/php.1 ${PREFIX}/${PKGMANDIR}/man1/php.1
	${INSTALL_DATA_DIR} ${CGIDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cgi/php ${CGIDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} php.ini-dist php.ini-recommended ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/php
	${INSTALL_DATA} ${WRKSRC}/php.gif ${PREFIX}/share/php

.include "../../mk/bsd.pkg.mk"
