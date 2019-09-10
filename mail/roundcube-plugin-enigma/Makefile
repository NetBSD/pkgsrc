# $NetBSD: Makefile,v 1.5.2.1 2019/09/10 18:10:55 bsiegert Exp $

PLUGIN=		enigma

MAINTAINER=	taca@NetBSD.org
COMMENT=	Enigma Plugin for Roundcube
LICENSE=	gnu-gpl-v3

# JavaScript dependencies from bin/install-jsdeps.sh
SITES.openpgp.min.js=	https://raw.githubusercontent.com/openpgpjs/openpgpjs/v2.6.2/dist/
DISTFILES+=	openpgp.min.js

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Crypt_GPG>=1.4.3:../../security/pear-Crypt_GPG

do-install: plugin-install
	${INSTALL_DATA} ${WRKDIR}/openpgp.min.js \
	  	${DESTDIR}${PREFIX}/${RCDIR}/plugins/enigma/openpgp.min.js

.include "../../mail/roundcube/plugins.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
