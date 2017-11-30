# $NetBSD: Makefile,v 1.3 2017/11/30 16:45:39 adam Exp $

PKGNAME=		csharp-${PKGNAME_MODULE}
PKGREVISION=		2
COMMENT=		C\# bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/csharp/

CONFIGURE_ARGS+=	--with-csharp

.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
