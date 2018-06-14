# $NetBSD: Makefile,v 1.14 2018/06/14 10:53:10 fhajny Exp $

DISTNAME=	node-v8.11.3

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

.include "options.mk"

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
