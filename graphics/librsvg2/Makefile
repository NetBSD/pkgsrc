# $NetBSD: Makefile,v 1.32 2004/12/05 23:26:16 recht Exp $
#

.include "Makefile.common"

PKGNAME=		${DISTNAME:S/-/2-/}
PKGREVISION=	1

USE_DIRS+=		xdg-1.1

CONFIGURE_ARGS+=	--disable-pixbuf-loader

CFLAGS.Darwin+=		-flat_namespace -undefined suppress
LDFLAGS.Darwin+=	-lfreetype -lfontconfig

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libcroco/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
