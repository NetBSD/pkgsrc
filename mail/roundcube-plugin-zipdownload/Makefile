# $NetBSD: Makefile,v 1.1 2016/09/13 16:03:38 taca Exp $

PLUGIN=		zipdownload

MAINTAINER=	taca@NetBSD.org
COMMENT=	Roundcube Webmail ZipDownload plugin
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.4.0:../../archivers/php-zip

PLUGIN=		zipdownload

do-install: plugin-install

.include "../../mail/roundcube/plugins.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
