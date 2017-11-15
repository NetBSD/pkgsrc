# $NetBSD: Makefile,v 1.113 2017/11/15 21:37:44 fhajny Exp $

DISTNAME=	node-v9.2.0

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
