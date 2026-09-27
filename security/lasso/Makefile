# $NetBSD: Makefile,v 1.70 2026/09/27 11:38:24 tnn Exp $

CONFIGURE_ENV+=		INKSCAPE=/bin/false
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-php7
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--enable-gtk-doc

EXTRACT_USING=		bsdtar

BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.32nb9
PKGREVISION= 4
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../security/lasso/Makefile.common"
.include "../../mk/bsd.pkg.mk"
