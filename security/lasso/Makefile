# $NetBSD: Makefile,v 1.50 2021/12/08 16:02:33 adam Exp $

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-php7
CONFIGURE_ARGS+=	--disable-perl

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.4.1
PYTHON_FOR_BUILD_ONLY=		yes

EXTRACT_USING=		bsdtar

#PKGREVISION= 1
PKGREVISION= 1
.include "../../security/lasso/Makefile.common"
