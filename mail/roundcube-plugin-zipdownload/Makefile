# $NetBSD: Makefile,v 1.2 2019/04/25 07:33:04 maya Exp $

PLUGIN=		zipdownload

MAINTAINER=	taca@NetBSD.org
COMMENT=	Roundcube Webmail ZipDownload plugin
PKGREVISION=	1
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.4.0:../../archivers/php-zip

PLUGIN=		zipdownload

do-install: plugin-install

.include "../../mail/roundcube/plugins.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
