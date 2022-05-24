# $NetBSD: Makefile,v 1.41 2022/05/24 18:59:21 jaapb Exp $
#

DISTNAME=	${GITHUB_PROJECT}-4.0.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}
GITHUB_PROJECT=	js_of_ocaml

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://ocsigen.org/js_of_ocaml/
COMMENT=	Compiler of OCaml bytecode to Javascript
LICENSE=	gnu-lgpl-v2

USE_TOOLS=	bash

OCAML_USE_FINDLIB=	yes
OCAML_USE_DUNE=		yes

OPAM_INSTALL_FILES=	js_of_ocaml js_of_ocaml-toplevel \
			js_of_ocaml-ppx js_of_ocaml-ppx_deriving_json \
			js_of_ocaml-compiler
DUNE_BUILD_PACKAGES=	${OPAM_INSTALL_FILES}

.include "options.mk"
.include "../../devel/menhir/buildlink3.mk"
.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../devel/ocaml-lwt_log/buildlink3.mk"
.include "../../devel/ocaml-ppx_expect/buildlink3.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../devel/ocaml-yojson/buildlink3.mk"
.include "../../math/ocaml-num/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
