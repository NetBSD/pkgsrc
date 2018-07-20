# $NetBSD: Makefile,v 1.15 2018/07/20 03:33:52 ryoon Exp $

DISTNAME=	node-v8.11.3

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

PKGREVISION= 1
.include "options.mk"

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
