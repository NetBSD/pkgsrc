# $NetBSD: Makefile,v 1.2 2009/05/26 05:26:00 manu Exp $
#

PKGREVISION=	2

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php4
CONFIGURE_ARGS+=	--disable-perl

PKG_DESTDIR_SUPPORT=	destdir

PYTHON_FOR_BUILD_ONLY=	yes

.include "../../security/lasso/Makefile.common"
