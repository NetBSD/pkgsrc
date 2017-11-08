# $NetBSD: Makefile,v 1.112 2017/11/08 17:02:41 fhajny Exp $

DISTNAME=	node-v9.1.0

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
