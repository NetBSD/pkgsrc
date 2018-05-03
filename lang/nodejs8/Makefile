# $NetBSD: Makefile,v 1.11 2018/05/03 21:12:23 fhajny Exp $

DISTNAME=	node-v8.11.1

# Stated by the changelog as of 8.2.0
GCC_REQD+=	4.9.4

.include "options.mk"

CONFIGURE_ARGS+=	--with-intl=system-icu

PKGREVISION= 2
.include "../../lang/nodejs/Makefile.common"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
