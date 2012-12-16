# $NetBSD: Makefile,v 1.16 2012/12/16 01:52:33 obache Exp $
#

PKGREVISION=		10

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-perl

PKG_DESTDIR_SUPPORT=	destdir

PYTHON_FOR_BUILD_ONLY=	yes

EXTRACT_USING=		bsdtar

.include "../../security/lasso/Makefile.common"
