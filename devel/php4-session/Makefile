# $NetBSD: Makefile,v 1.6 2002/08/01 00:58:31 mycroft Exp $

MODNAME=		session
CATEGORIES+=		devel
PKGREVISION=		1
COMMENT=		PHP4 extension for session-handling

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}
#CONFIGURE_ARGS+=	--with-mm=shared,${BUILDLINK_DIR}

#.include "../../devel/libmm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
