# $NetBSD: Makefile,v 1.13 2020/06/02 08:24:50 adam Exp $

PKGNAME=		csharp-${PKGNAME_MODULE}
PKGREVISION=		2
COMMENT=		C\# bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/csharp/

CONFIGURE_ARGS+=	--with-csharp

.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
