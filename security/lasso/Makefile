# $NetBSD: Makefile,v 1.22 2014/05/29 23:37:19 wiz Exp $
#

PKGREVISION=		16

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-perl

PKG_DESTDIR_SUPPORT=	destdir

PYTHON_FOR_BUILD_ONLY=	yes

EXTRACT_USING=		bsdtar

.include "../../security/lasso/Makefile.common"
