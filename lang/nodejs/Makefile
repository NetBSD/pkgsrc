# $NetBSD: Makefile,v 1.107 2017/09/27 12:17:10 fhajny Exp $

DISTNAME=	node-v8.6.0

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
