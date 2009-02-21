# $NetBSD: Makefile,v 1.10 2009/02/21 12:56:12 adrianp Exp $

MODNAME=		mbstring
CATEGORIES+=		misc
COMMENT=		PHP extension for multibyte characters support (currently, Japanese only)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-mbstring-[0-9]*

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../mk/bsd.prefs.mk"

# Work around for pdksh bug documented in PR#40709
# This should work on at least SunOS 5.10 and 5.11
.if ${OPSYS} == "SunOS"
CONFIG_SHELL=		/usr/bin/ksh
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
