# $NetBSD: Makefile,v 1.99 2017/06/05 21:14:04 fhajny Exp $

DISTNAME=	node-v8.0.0

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
