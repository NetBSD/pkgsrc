# $NetBSD: Makefile,v 1.17 2013/02/06 23:21:33 jperkin Exp $
#

PKGREVISION=		11

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-perl

PKG_DESTDIR_SUPPORT=	destdir

PYTHON_FOR_BUILD_ONLY=	yes

EXTRACT_USING=		bsdtar

.include "../../security/lasso/Makefile.common"
