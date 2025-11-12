# $NetBSD: Makefile,v 1.9 2025/11/12 12:24:27 jperkin Exp $

MODNAME=		opcache
PKGREVISION=		1
CATEGORIES+=		devel
COMMENT=		PHP extension for opcode caching

PHP_ZEND_EXTENSION=	yes
CONFIGURE_ARGS+=	--enable-${MODNAME}=opcache
USE_PHP_EXT_PATCHES=	Yes

# Ensure libgcc's __builtin_cpu_* stuff is pulled in.
LDFLAGS.SunOS+=	-lgcc

# PHP 8.4's opcache depends on gmake.
.include "../../lang/php/phpversion.mk"
.if ${PHP_VER} >= 84
USE_TOOLS+=	gmake
.endif

TEST_TARGET=	test

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
