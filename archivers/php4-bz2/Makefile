# $NetBSD: Makefile,v 1.3 2002/02/28 06:16:39 jlam Exp $

MODNAME=		bz2
CATEGORIES+=		archivers
PKGREVISION=		# empty
COMMENT=		PHP4 extension for bzip2 compression

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../archivers/bzip2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
