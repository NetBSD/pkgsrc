# $NetBSD: Makefile,v 1.31 2017/01/01 14:43:54 wiz Exp $

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-perl

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 2.4.1
PYTHON_FOR_BUILD_ONLY=	yes

EXTRACT_USING=		bsdtar

#PKGREVISION= 1
PKGREVISION= 1
.include "../../security/lasso/Makefile.common"
