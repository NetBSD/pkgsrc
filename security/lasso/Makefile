# $NetBSD: Makefile,v 1.29 2016/07/09 06:38:54 wiz Exp $

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-perl

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 2.4.1
PYTHON_FOR_BUILD_ONLY=	yes

EXTRACT_USING=		bsdtar

#PKGREVISION= 1
PKGREVISION= 1
.include "../../security/lasso/Makefile.common"
