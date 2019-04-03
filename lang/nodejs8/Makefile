# $NetBSD: Makefile,v 1.20 2019/04/03 00:32:50 ryoon Exp $

DISTNAME=	node-v8.12.0

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

PKGREVISION= 3
.include "options.mk"

CONFIGURE_ARGS+=	--with-intl=system-icu

.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
