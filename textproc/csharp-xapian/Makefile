# $NetBSD: Makefile,v 1.4 2018/04/14 07:34:42 adam Exp $

PKGNAME=		csharp-${PKGNAME_MODULE}
PKGREVISION=		3
COMMENT=		C\# bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/csharp/

CONFIGURE_ARGS+=	--with-csharp

.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
