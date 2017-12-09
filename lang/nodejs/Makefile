# $NetBSD: Makefile,v 1.115 2017/12/09 17:56:10 fhajny Exp $

DISTNAME=	node-v9.2.1

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
