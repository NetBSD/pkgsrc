# $NetBSD: Makefile,v 1.29 2004/05/15 17:25:42 minskim Exp $
#

.include "Makefile.common"

PKGNAME=		${DISTNAME:S/-/2-/}

CONFIGURE_ARGS+=	--disable-pixbuf-loader

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libcroco/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
