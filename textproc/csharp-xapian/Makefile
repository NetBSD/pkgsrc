# $NetBSD: Makefile,v 1.25 2022/09/26 16:13:47 wiz Exp $

PKGNAME=		csharp-${PKGNAME_MODULE}
PKGREVISION=		1
COMMENT=		C\# bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/csharp/

CONFIGURE_ARGS+=	--with-csharp

.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
