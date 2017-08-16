# $NetBSD: Makefile,v 1.105 2017/08/16 11:52:19 fhajny Exp $

DISTNAME=	node-v8.4.0

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
