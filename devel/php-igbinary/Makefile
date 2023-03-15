# $NetBSD: Makefile,v 1.9 2023/03/15 13:53:54 taca Exp $

MODNAME=	igbinary
PECL_VERSION=	3.2.14
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

INSTALLATION_DIRS+=	include/php/ext/igbinary

post-install:
	${INSTALL_DATA} ${WRKSRC}/igbinary.h \
		${DESTDIR}${PREFIX}/include/php/ext/igbinary

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
