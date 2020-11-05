# $NetBSD: Makefile,v 1.15 2020/11/05 09:09:13 ryoon Exp $

PKGNAME=		csharp-${PKGNAME_MODULE}
PKGREVISION=		1
COMMENT=		C\# bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/csharp/

CONFIGURE_ARGS+=	--with-csharp

.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
