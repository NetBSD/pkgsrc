# $NetBSD: Makefile,v 1.16 2018/08/16 12:51:50 fhajny Exp $

DISTNAME=	node-v8.11.4

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

.include "options.mk"

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
