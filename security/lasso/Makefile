# $NetBSD: Makefile,v 1.3 2009/12/01 08:49:46 manu Exp $
#

PKGREVISION=	3

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php4
CONFIGURE_ARGS+=	--disable-perl

PKG_DESTDIR_SUPPORT=	destdir

PYTHON_FOR_BUILD_ONLY=	yes

.include "../../security/lasso/Makefile.common"
