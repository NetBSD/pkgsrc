# $NetBSD: Makefile,v 1.28 2014/02/12 23:18:29 tron Exp $

.include "../../print/evince3/Makefile.common"

PKGREVISION=		1

COMMENT=		Document viewer

.include "options.mk"

CONFIGURE_ARGS+=	--enable-comics
CONFIGURE_ARGS+=	--disable-nautilus

USE_TOOLS+=	gsed

CONFIGURE_ARGS+=	--disable-compile-warnings

.include "../../devel/glib2/schemas.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
