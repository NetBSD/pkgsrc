# $NetBSD: Makefile,v 1.18 2021/03/08 08:12:47 jaapb Exp $

GITHUB_PROJECT=	pgocaml
#GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-4.2.2
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=darioteixeira/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://pgocaml.forge.ocamlcore.org/
COMMENT=	Native PostgreSQL binding for OCaml
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c
USE_TOOLS+=	bash
REPLACE_BASH=	src/genconfig.sh

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	pgocaml pgocaml_ppx
OPAM_INSTALL_FILES=	${DUNE_BUILD_PACKAGES}

.include "../../mk/ocaml.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocaml-hex/buildlink3.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../devel/ocaml-ppx_deriving/buildlink3.mk"
.include "../../devel/ocaml-ppx_optcomp/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_conv/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-ppx_tools=	build
.include "../../devel/ocaml-ppx_tools/buildlink3.mk"
.include "../../devel/ocaml-ppx_tools_versioned/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-rresult=	build
.include "../../devel/ocaml-rresult/buildlink3.mk"
.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../textproc/ocaml-csv/buildlink3.mk"
.include "../../time/ocaml-calendar/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
