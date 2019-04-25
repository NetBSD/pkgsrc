# $NetBSD: Makefile,v 1.4 2019/04/25 07:33:04 maya Exp $

PLUGIN=		enigma

MAINTAINER=	taca@NetBSD.org
COMMENT=	Enigma Plugin for Roundcube
PKGREVISION=	1
LICENSE=	gnu-gpl-v3

# JavaScript dependencies from bin/install-jsdeps.sh
SITES.openpgp.min.js=	"https://raw.githubusercontent.com/openpgpjs/openpgpjs/v2.6.2/dist/"
DISTFILES+=	openpgp.min.js

PLUGIN=		enigma

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Crypt_GPG>=1.4.3:../../security/pear-Crypt_GPG

do-install: plugin-install
	${INSTALL_DATA} ${WRKDIR}/openpgp.min.js \
	  	${DESTDIR}${PREFIX}/${RCDIR}/plugins/enigma/openpgp.min.js

.include "../../mail/roundcube/plugins.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
