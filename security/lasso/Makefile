# $NetBSD: Makefile,v 1.45 2020/11/05 09:07:06 ryoon Exp $

CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-php5
CONFIGURE_ARGS+=	--disable-perl

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.4.1
PYTHON_FOR_BUILD_ONLY=		yes

EXTRACT_USING=		bsdtar

#PKGREVISION= 1
PKGREVISION= 2
.include "../../security/lasso/Makefile.common"
