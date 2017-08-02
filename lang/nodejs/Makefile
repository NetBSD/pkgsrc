# $NetBSD: Makefile,v 1.104 2017/08/02 17:31:45 fhajny Exp $

DISTNAME=	node-v8.2.1

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
