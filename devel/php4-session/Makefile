# $NetBSD: Makefile,v 1.4 2001/12/03 08:31:01 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		session
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for session-handling

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}
#CONFIGURE_ARGS+=	--with-mm=shared,${BUILDLINK_DIR}

#.include "../../devel/libmm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
