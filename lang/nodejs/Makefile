# $NetBSD: Makefile,v 1.110 2017/10/26 09:12:55 fhajny Exp $

DISTNAME=	node-v8.8.1

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
