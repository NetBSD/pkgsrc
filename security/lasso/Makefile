# $NetBSD: Makefile,v 1.60 2023/11/08 13:20:47 wiz Exp $

PKGREVISION=	11

CONFIGURE_ENV+=		INKSCAPE=/bin/false
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-php7
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--enable-gtk-doc

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.4.1
PYTHON_FOR_BUILD_ONLY=		yes

EXTRACT_USING=		bsdtar

BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.32nb9
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../security/lasso/Makefile.common"
