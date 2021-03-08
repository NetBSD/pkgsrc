# $NetBSD: Makefile,v 1.5 2021/03/08 08:12:57 jaapb Exp $

GITHUB_PROJECT=	ppx_jane
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.13.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_jane/
COMMENT=	Standard Jane Street PPX rewriters for OCaml
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../devel/ocaml-base_quickcheck/buildlink3.mk"
.include "../../devel/ocaml-ppx_assert/buildlink3.mk"
.include "../../devel/ocaml-ppx_base/buildlink3.mk"
.include "../../devel/ocaml-ppx_bench/buildlink3.mk"
.include "../../devel/ocaml-ppx_bin_prot/buildlink3.mk"
.include "../../devel/ocaml-ppx_custom_printf/buildlink3.mk"
.include "../../devel/ocaml-ppx_expect/buildlink3.mk"
.include "../../devel/ocaml-ppx_fail/buildlink3.mk"
.include "../../devel/ocaml-ppx_fields_conv/buildlink3.mk"
.include "../../devel/ocaml-ppx_here/buildlink3.mk"
.include "../../devel/ocaml-ppx_inline_test/buildlink3.mk"
.include "../../devel/ocaml-ppx_let/buildlink3.mk"
.include "../../devel/ocaml-ppx_module_timer/buildlink3.mk"
.include "../../devel/ocaml-ppx_optcomp/buildlink3.mk"
.include "../../devel/ocaml-ppx_optional/buildlink3.mk"
.include "../../devel/ocaml-ppx_pipebang/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_message/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_value/buildlink3.mk"
.include "../../devel/ocaml-ppx_stable/buildlink3.mk"
.include "../../devel/ocaml-ppx_typerep_conv/buildlink3.mk"
.include "../../devel/ocaml-ppx_variants_conv/buildlink3.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
