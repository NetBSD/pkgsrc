# $NetBSD: Makefile,v 1.5 2002/02/28 06:17:44 jlam Exp $

MODNAME=		session
CATEGORIES+=		devel
PKGREVISION=		# empty
COMMENT=		PHP4 extension for session-handling

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}
#CONFIGURE_ARGS+=	--with-mm=shared,${BUILDLINK_DIR}

#.include "../../devel/libmm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
