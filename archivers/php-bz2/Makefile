# $NetBSD: Makefile,v 1.6 2005/10/23 18:12:24 rillig Exp $

MODNAME=		bz2
CATEGORIES+=		archivers
COMMENT=		PHP extension for bzip2 compression

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.bzip2}

.include "../../lang/php/ext.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
