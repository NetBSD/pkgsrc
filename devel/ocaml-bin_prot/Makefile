# $NetBSD: Makefile,v 1.9 2026/03/01 12:38:21 gdt Exp $

DISTNAME=	${GITHUB_PROJECT}-0.14.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	bin_prot
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/bin_prot/
COMMENT=	Binary protocol generator for OCaml
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-ppx_compare/buildlink3.mk"
.include "../../devel/ocaml-ppx_custom_printf/buildlink3.mk"
.include "../../devel/ocaml-ppx_fields_conv/buildlink3.mk"
.include "../../devel/ocaml-ppx_optcomp/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_conv/buildlink3.mk"
.include "../../devel/ocaml-ppx_variants_conv/buildlink3.mk"

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
