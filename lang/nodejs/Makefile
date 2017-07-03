# $NetBSD: Makefile,v 1.102 2017/07/03 15:14:47 fhajny Exp $

DISTNAME=	node-v8.1.3

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
