# $NetBSD: Makefile,v 1.20 2014/02/05 09:26:58 manu Exp $
#

PKGREVISION=		14

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-perl

PKG_DESTDIR_SUPPORT=	destdir

PYTHON_FOR_BUILD_ONLY=	yes

EXTRACT_USING=		bsdtar

.include "../../security/lasso/Makefile.common"
