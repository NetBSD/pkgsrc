# $NetBSD: Makefile,v 1.3 2003/08/31 19:55:26 jdolecek Exp $

MODNAME=		iconv
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for character set conversion

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

# this is necessary so that PHP would find either the libc iconv
# or use the packaged iconv, as appropriate; using
# --with-iconv=shared,${BUILDLINK_PREFIX.iconv} assumes libiconv exists
# the PHP_ICONV in environment is to make configure find alternative
# libiconv
CONFIGURE_ARGS+=	--with-iconv
CONFIGURE_ENV+=		PHP_ICONV=${BUILDLINK_PREFIX.iconv:Q}

.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
