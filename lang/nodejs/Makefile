# $NetBSD: Makefile,v 1.101 2017/06/15 18:16:56 fhajny Exp $

DISTNAME=	node-v8.1.2

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
