# $NetBSD: Makefile,v 1.103 2020/11/21 09:34:57 wiz Exp $

PKGREVISION= 8
.include "../../print/evince3/Makefile.common"

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
BUILDLINK_DEPMETHOD.libXt=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
