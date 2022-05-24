# $NetBSD: Makefile,v 1.6 2022/05/24 18:59:23 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	core
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/core/
COMMENT=	Standard library overlay for OCaml by Jane Street
LICENSE=	mit

USE_TOOLS+=	bash

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-base_bigstring/buildlink3.mk"
.include "../../devel/ocaml-base_quickcheck/buildlink3.mk"
.include "../../devel/ocaml-bin_prot/buildlink3.mk"
.include "../../devel/ocaml-fieldslib/buildlink3.mk"
.include "../../devel/ocaml-jane-street-headers/buildlink3.mk"
.include "../../devel/ocaml-jst-config/buildlink3.mk"
.include "../../devel/ocaml-ppx_assert/buildlink3.mk"
.include "../../devel/ocaml-ppx_base/buildlink3.mk"
.include "../../devel/ocaml-ppx_hash/buildlink3.mk"
.include "../../devel/ocaml-ppx_inline_test/buildlink3.mk"
.include "../../devel/ocaml-ppx_jane/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_conv/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_message/buildlink3.mk"
.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../devel/ocaml-splittable_random/buildlink3.mk"
.include "../../devel/ocaml-stdio/buildlink3.mk"
.include "../../devel/ocaml-typerep/buildlink3.mk"
.include "../../devel/ocaml-variantslib/buildlink3.mk"
.include "../../time/ocaml-time_now/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
