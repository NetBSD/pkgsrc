# $NetBSD: Makefile,v 1.1.1.1 2001/10/16 06:34:42 jlam Exp $

.include "../php4/Makefile.module"

MODNAME=		session
CATEGORIES=		devel
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for session-handling

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}
#CONFIGURE_ARGS+=	--with-mm=shared,${BUILDLINK_DIR}

#.include "../../devel/libmm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
