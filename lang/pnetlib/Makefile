# $NetBSD: Makefile,v 1.2 2004/02/27 07:37:04 xtraeme Exp $
#

.include "Makefile.common"

USE_X11=		yes

CONFIGURE_ARGS+=	--enable-xft
CONFIGURE_ARGS+=	--with-x

PLIST_SUBST+=		WITH_X11=

CONFLICTS=		pnetlib-nox11-[0-9]*

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
