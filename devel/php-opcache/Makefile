# $NetBSD: Makefile,v 1.10 2026/01/02 06:17:43 taca Exp $

MODNAME=		opcache
PKGREVISION=		1
CATEGORIES+=		devel
COMMENT=		PHP extension for opcode caching

PHP_ZEND_EXTENSION=	yes
CONFIGURE_ARGS+=	--enable-${MODNAME}=opcache
USE_PHP_EXT_PATCHES=	Yes

# Ensure libgcc's __builtin_cpu_* stuff is pulled in.
LDFLAGS.SunOS+=	-lgcc

# PHP 8.5 bundles opcache extension.
PHP_VERSIONS_ACCEPTED=	83 82 84 81 74 56

# PHP 8.4's opcache depends on gmake.
.include "../../lang/php/phpversion.mk"
.if ${PHP_VER} == 84
USE_TOOLS+=	gmake
.endif

TEST_TARGET=	test

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
