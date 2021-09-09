# $NetBSD: Makefile,v 1.8 2021/09/09 01:11:44 khorben Exp $

PLUGIN=		zipdownload
PKGREVISION=	1

MAINTAINER=	taca@NetBSD.org
COMMENT=	Roundcube Webmail ZipDownload plugin
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.4.0:../../archivers/php-zip

.include "../../mail/roundcube/plugins.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
