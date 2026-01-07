# $NetBSD: Makefile,v 1.68 2026/01/07 08:48:42 wiz Exp $

CONFIGURE_ENV+=		INKSCAPE=/bin/false
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-php7
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--enable-gtk-doc

EXTRACT_USING=		bsdtar

BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.32nb9
PKGREVISION= 2
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../security/lasso/Makefile.common"
.include "../../mk/bsd.pkg.mk"
