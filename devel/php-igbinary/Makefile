# $NetBSD: Makefile,v 1.12 2025/02/08 03:41:13 taca Exp $

MODNAME=	igbinary
PECL_VERSION=	3.2.16
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/igbinary/igbinary
COMMENT=	Binary serialization for PHP
LICENSE=	modified-bsd

PHP_VERSIONS_INCOMPATIBLE=	56

USE_LANGUAGES=		c c++
USE_TOOLS+=		gsed
CONFIGURE_ARGS+=	--enable-${MODNAME}

PLIST_SRC+=		PLIST

INSTALLATION_DIRS+=	${PHP_INCDIR}/ext/igbinary

post-install:
	${INSTALL_DATA} ${WRKSRC}/igbinary.h \
		${DESTDIR}${PREFIX}/${PHP_INCDIR}/ext/igbinary

.include "../../www/php-apcu/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
