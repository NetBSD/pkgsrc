# $NetBSD: Makefile,v 1.97 2017/05/12 20:55:40 fhajny Exp $

DISTNAME=	node-v7.10.0

CONFIGURE_ARGS+=        --with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
