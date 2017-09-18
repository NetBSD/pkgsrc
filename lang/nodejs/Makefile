# $NetBSD: Makefile,v 1.106 2017/09/18 09:53:25 maya Exp $

DISTNAME=	node-v8.4.0

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

CONFIGURE_ARGS+=	--with-intl=system-icu

PKGREVISION= 1
.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
