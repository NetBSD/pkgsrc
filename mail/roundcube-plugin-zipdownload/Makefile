# $NetBSD: Makefile,v 1.5 2020/01/14 14:34:08 taca Exp $

PLUGIN=		zipdownload

MAINTAINER=	taca@NetBSD.org
COMMENT=	Roundcube Webmail ZipDownload plugin
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.4.0:../../archivers/php-zip

.include "../../mail/roundcube/plugins.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
