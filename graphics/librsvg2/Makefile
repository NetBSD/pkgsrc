# $NetBSD: Makefile,v 1.23 2004/02/11 06:22:08 xtraeme Exp $
#

.include "Makefile.common"

PKGNAME=		${DISTNAME:S/-/2-/}
PKGREVISION=		6

CONFIGURE_ARGS+=	--disable-pixbuf-loader

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libcroco/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
