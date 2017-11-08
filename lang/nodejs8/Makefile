# $NetBSD: Makefile,v 1.2 2017/11/08 17:44:02 fhajny Exp $

DISTNAME=	node-v8.9.1

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
