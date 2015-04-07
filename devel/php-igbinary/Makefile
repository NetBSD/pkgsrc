# $NetBSD: Makefile,v 1.1 2015/04/07 11:23:09 rodent Exp $
#

MODNAME=	igbinary
PECL_VERSION=	1.2.1
CATEGORIES=	devel

MAINTAINER=	mbowie@buzmo.com
HOMEPAGE=	https://github.com/igbinary/igbinary
COMMENT=	Binary serialization for PHP
LICENSE=	modified-bsd

BUILD_DEPENDS+=	re2c>=0.13.0.4:../../devel/re2c

USE_LANGUAGES=		c c++
USE_TOOLS+=		gsed
CONFIGURE_ARGS+=	--enable-${MODNAME}
USE_LIBTOOL=		yes

USE_PHP_EXT_PATCHES=	yes

PLIST_SRC+=		PLIST

INSTALLATION_DIRS+=	include/php/ext/igbinary

post-install:
	${INSTALL_DATA} ${WRKSRC}/igbinary.h \
		${DESTDIR}${PREFIX}/include/php/ext/igbinary

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
