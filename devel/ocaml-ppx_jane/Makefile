# $NetBSD: Makefile,v 1.7 2022/05/24 18:59:29 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	ppx_jane
GITHUB_TAG=	v${PKGVERSION_NOREV}

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
.include "../../devel/ocaml-ppx_disable_unused_warnings/buildlink3.mk"
.include "../../devel/ocaml-ppx_expect/buildlink3.mk"
.include "../../devel/ocaml-ppx_fail/buildlink3.mk"
.include "../../devel/ocaml-ppx_fields_conv/buildlink3.mk"
.include "../../devel/ocaml-ppx_fixed_literal/buildlink3.mk"
.include "../../devel/ocaml-ppx_here/buildlink3.mk"
.include "../../devel/ocaml-ppx_ignore_instrumentation/buildlink3.mk"
.include "../../devel/ocaml-ppx_inline_test/buildlink3.mk"
.include "../../devel/ocaml-ppx_let/buildlink3.mk"
.include "../../devel/ocaml-ppx_log/buildlink3.mk"
.include "../../devel/ocaml-ppx_module_timer/buildlink3.mk"
.include "../../devel/ocaml-ppx_optcomp/buildlink3.mk"
.include "../../devel/ocaml-ppx_optional/buildlink3.mk"
.include "../../devel/ocaml-ppx_pipebang/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_message/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_value/buildlink3.mk"
.include "../../devel/ocaml-ppx_stable/buildlink3.mk"
.include "../../devel/ocaml-ppx_string/buildlink3.mk"
.include "../../devel/ocaml-ppx_typerep_conv/buildlink3.mk"
.include "../../devel/ocaml-ppx_variants_conv/buildlink3.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
