# $NetBSD: Makefile,v 1.1.1.1 2001/10/16 07:02:12 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		bz2
CATEGORIES+=		archivers
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for bzip2 compression

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../archivers/bzip2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
