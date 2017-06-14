# $NetBSD: Makefile,v 1.100 2017/06/14 12:59:14 fhajny Exp $

DISTNAME=	node-v8.1.1

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
