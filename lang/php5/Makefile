# $NetBSD: Makefile,v 1.1.1.1 2004/10/29 20:31:54 jdolecek Exp $
#

PKGNAME=		php-${PHP5_VERSION}
CATEGORIES=		lang

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.php.net/
COMMENT=		PHP Hypertext Preprocessor version 5

USE_PKGINSTALL=		YES
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
LIBTOOL_OVERRIDE=	# empty

.include "Makefile.common"

EGDIR=			${PREFIX}/share/examples/php

CONF_FILES=		${EGDIR}/php.ini-recommended ${PKG_SYSCONFDIR}/php.ini
OWN_DIRS=		${PREFIX}/${PHP_EXTENSION_DIR}

post-install:
	@${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} php.ini-dist php.ini-recommended ${EGDIR}

.include "../../mk/bsd.pkg.mk"
