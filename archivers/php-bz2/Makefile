# $NetBSD: Makefile,v 1.7 2005/11/04 09:18:30 rillig Exp $

MODNAME=		bz2
CATEGORIES=		archivers
COMMENT=		PHP extension for bzip2 compression

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.bzip2}

.include "../../lang/php/ext.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
