# $NetBSD: Makefile,v 1.7 2002/09/07 19:09:43 hubertf Exp $

MODNAME=		session
CATEGORIES+=		devel
PKGREVISION=		2
COMMENT=		PHP4 extension for session-handling

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--enable-trans-sid
#CONFIGURE_ARGS+=	--with-mm=shared,${BUILDLINK_DIR}

#.include "../../devel/libmm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
