# $NetBSD: Makefile,v 1.67 2025/10/23 20:39:08 wiz Exp $

CONFIGURE_ENV+=		INKSCAPE=/bin/false
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-php7
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--enable-gtk-doc

EXTRACT_USING=		bsdtar

BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.32nb9
PKGREVISION= 1
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../security/lasso/Makefile.common"
.include "../../mk/bsd.pkg.mk"
