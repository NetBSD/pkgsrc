# $NetBSD: Makefile,v 1.98 2017/05/30 14:26:38 adam Exp $

DISTNAME=	node-v7.10.0

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
