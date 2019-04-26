# $NetBSD: Makefile,v 1.36 2019/04/26 14:12:44 maya Exp $

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-perl

PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 2.4.1
PYTHON_FOR_BUILD_ONLY=	yes

EXTRACT_USING=		bsdtar

PKGREVISION= 2
.include "../../security/lasso/Makefile.common"
