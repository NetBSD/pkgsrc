# $NetBSD: Makefile,v 1.12 2011/11/01 06:01:56 sbd Exp $
#

PKGREVISION=		1

.include "Makefile.common"

CONFIGURE_ARGS+=	--enable-xft
CONFIGURE_ARGS+=	--with-x

CONFLICTS=		pnetlib-nox11-[0-9]*

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
