# $NetBSD: Makefile,v 1.33 2018/08/22 09:46:18 wiz Exp $

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-perl

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 2.4.1
PYTHON_FOR_BUILD_ONLY=	yes

EXTRACT_USING=		bsdtar

#PKGREVISION= 1
PKGREVISION= 2
.include "../../security/lasso/Makefile.common"
