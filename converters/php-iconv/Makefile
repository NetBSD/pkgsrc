# $NetBSD: Makefile,v 1.1.1.1 2004/10/31 19:30:30 jdolecek Exp $

MODNAME=		iconv
CATEGORIES+=		converters
PKGREVISION=		# empty
COMMENT=		PHP extension for character set conversion

USE_BUILDLINK3=		YES

# this is necessary so that PHP would find either the libc iconv
# or use the packaged iconv, as appropriate; using
# --with-iconv=shared,${BUILDLINK_PREFIX.iconv} assumes libiconv exists

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/buildlink3/bsd.builtin.mk"

.if !empty(USE_BUILTIN.iconv:M[nN][oO])
# use libiconv
CONFIGURE_ARGS+=	--with-iconv=shared,${BUILDLINK_PREFIX.iconv}
.else
# use libc-provided iconv
CONFIGURE_ARGS+=	--with-iconv
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
