# $NetBSD: Makefile,v 1.5 2018/07/06 16:23:11 schmonz Exp $

PKGNAME=		csharp-${PKGNAME_MODULE}
COMMENT=		C\# bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/csharp/

CONFIGURE_ARGS+=	--with-csharp

.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
