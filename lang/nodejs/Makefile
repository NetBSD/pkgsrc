# $NetBSD: Makefile,v 1.103 2017/07/11 19:00:57 fhajny Exp $

DISTNAME=	node-v8.1.4

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
