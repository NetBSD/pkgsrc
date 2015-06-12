# $NetBSD: Makefile,v 1.25 2015/06/12 10:51:02 wiz Exp $

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-perl

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 2.4.1
PYTHON_FOR_BUILD_ONLY=	yes

EXTRACT_USING=		bsdtar

PKGREVISION= 1
.include "../../security/lasso/Makefile.common"
