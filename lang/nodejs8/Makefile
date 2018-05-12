# $NetBSD: Makefile,v 1.12 2018/05/12 08:59:56 fhajny Exp $

DISTNAME=	node-v8.11.1

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

.include "options.mk"

CONFIGURE_ARGS+=	--with-intl=system-icu

PKGREVISION= 3
.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
