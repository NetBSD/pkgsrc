# $NetBSD: Makefile,v 1.2 2003/07/13 13:50:53 wiz Exp $

MODNAME=		iconv
CATEGORIES+=		devel
PKGREVISION=		1
COMMENT=		PHP4 extension for character set conversion

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-iconv=shared,${BUILDLINK_PREFIX.iconv}

.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
