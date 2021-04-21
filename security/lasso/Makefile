# $NetBSD: Makefile,v 1.47 2021/04/21 11:40:37 adam Exp $

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-perl

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.4.1
PYTHON_FOR_BUILD_ONLY=		yes

EXTRACT_USING=		bsdtar

#PKGREVISION= 1
PKGREVISION= 4
.include "../../security/lasso/Makefile.common"
