# $NetBSD: Makefile,v 1.8 2002/10/09 18:27:46 wiz Exp $

MODNAME=		session
CATEGORIES+=		devel
PKGREVISION=		2
COMMENT=		PHP4 extension for session-handling

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--enable-trans-sid
#CONFIGURE_ARGS+=	--with-mm=shared,${BUILDLINK_DIR}

#.include "../../devel/libmm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
