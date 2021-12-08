# $NetBSD: Makefile,v 1.18 2021/12/08 16:06:43 adam Exp $

PKGNAME=		csharp-${PKGNAME_MODULE}
PKGREVISION=		2
COMMENT=		C\# bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/csharp/

CONFIGURE_ARGS+=	--with-csharp

.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
