# $NetBSD: Makefile,v 1.114 2017/11/30 16:45:28 adam Exp $

DISTNAME=	node-v9.2.0

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

CONFIGURE_ARGS+=	--with-intl=system-icu

PKGREVISION= 1
.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
