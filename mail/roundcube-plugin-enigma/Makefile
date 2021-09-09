# $NetBSD: Makefile,v 1.11 2021/09/09 01:11:43 khorben Exp $

PLUGIN=		enigma
PKGREVISION=	1

MAINTAINER=	taca@NetBSD.org
COMMENT=	Enigma Plugin for Roundcube
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Crypt_GPG>=1.4.3:../../security/pear-Crypt_GPG

REPLACE_PHP=	${PLUGIN_DIR}/import_keys.sh

.include "../../mail/roundcube/plugins.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
