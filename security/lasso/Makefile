# $NetBSD: Makefile,v 1.41 2020/03/08 16:48:07 wiz Exp $

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-perl

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.4.1
PYTHON_FOR_BUILD_ONLY=		yes

EXTRACT_USING=		bsdtar

PKGREVISION= 5
.include "../../security/lasso/Makefile.common"
