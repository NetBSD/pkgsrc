# $NetBSD: Makefile,v 1.4 2010/01/17 12:02:41 wiz Exp $
#

PKGREVISION=	4

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php4
CONFIGURE_ARGS+=	--disable-perl

PKG_DESTDIR_SUPPORT=	destdir

PYTHON_FOR_BUILD_ONLY=	yes

.include "../../security/lasso/Makefile.common"
