# $NetBSD: Makefile,v 1.21 2022/06/22 15:43:44 wiz Exp $

PKGNAME=		csharp-${PKGNAME_MODULE}
PKGREVISION=		2
COMMENT=		C\# bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/csharp/

CONFIGURE_ARGS+=	--with-csharp

.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
