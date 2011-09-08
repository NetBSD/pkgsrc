# $NetBSD: Makefile,v 1.8 2011/09/08 00:17:03 joerg Exp $
#

PKGREVISION=		2

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-perl

PKG_DESTDIR_SUPPORT=	destdir

PYTHON_FOR_BUILD_ONLY=	yes

EXTRACT_USING=		bsdtar

.include "../../security/lasso/Makefile.common"
