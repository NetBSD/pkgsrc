# $NetBSD: Makefile,v 1.22 2019/12/09 20:06:43 adam Exp $

DISTNAME=	node-v8.16.2

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

.include "options.mk"

CONFIGURE_ARGS+=	--shared-http-parser
CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../www/http-parser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
