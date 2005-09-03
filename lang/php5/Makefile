# $NetBSD: Makefile,v 1.14 2005/09/03 13:37:36 adrianp Exp $
#

PKGNAME=		php-${PHP_BASE_VERS}
PKGREVISION=		1
CATEGORIES=		lang

HOMEPAGE=		http://www.php.net/
COMMENT=		PHP Hypertext Preprocessor version 5

USE_PKGINSTALL=		YES
USE_TOOLS+=		gmake gzcat
LIBTOOL_OVERRIDE=	# empty

.include "Makefile.php"

CGIDIR=			${PREFIX}/libexec/cgi-bin
EGDIR=			${PREFIX}/share/examples/php

EXTRACT_ONLY=			${DISTNAME}${EXTRACT_SUFX}
XMLRPC_DISTFILE=		XML_RPC-1.4.0.tgz
SITES_${XMLRPC_DISTFILE}=	http://pear.php.net/get/
DISTFILES=			${EXTRACT_ONLY} ${XMLRPC_DISTFILE}

CONF_FILES=		${EGDIR}/php.ini-recommended ${PKG_SYSCONFDIR}/php.ini
OWN_DIRS=		${PREFIX}/${PHP_EXTENSION_DIR}

post-extract:
	${RM} -f ${WRKSRC}/pear/packages/XML_RPC-1.2.2.tar
	${GZCAT} ${DISTDIR}/${XMLRPC_DISTFILE} \
		>${WRKSRC}/pear/packages/${XMLRPC_DISTFILE:S/.tgz/.tar/}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cli/php ${PREFIX}/bin/php
	${INSTALL_DATA} ${WRKSRC}/sapi/cli/php.1 ${PREFIX}/man/man1/php.1
	${INSTALL_DATA_DIR} ${CGIDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cgi/php ${CGIDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} php.ini-dist php.ini-recommended ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/php
	${INSTALL_DATA} ${WRKSRC}/php.gif ${PREFIX}/share/php

.include "../../mk/bsd.pkg.mk"
