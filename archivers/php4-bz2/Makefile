# $NetBSD: Makefile,v 1.2 2001/12/03 08:30:58 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		bz2
CATEGORIES+=		archivers
PKGREVISION=		# empty
COMMENT=		PHP4 extension for bzip2 compression

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../archivers/bzip2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
