# $NetBSD: Makefile,v 1.22 2022/07/11 18:25:40 schmonz Exp $

PKGNAME=		csharp-${PKGNAME_MODULE}
COMMENT=		C\# bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/csharp/

CONFIGURE_ARGS+=	--with-csharp

.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
