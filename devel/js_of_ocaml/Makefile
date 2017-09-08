# $NetBSD: Makefile,v 1.21 2017/09/08 17:04:57 jaapb Exp $
#

GITHUB_PROJECT=	js_of_ocaml
DISTNAME=	${GITHUB_PROJECT}-3.0.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://ocsigen.org/js_of_ocaml/
COMMENT=	Compiler of OCaml bytecode to Javascript
LICENSE=	gnu-lgpl-v2

USE_TOOLS=	bash

OCAML_USE_FINDLIB=	yes
OCAML_USE_JBUILDER=	yes

OPAM_INSTALL_FILES=	js_of_ocaml js_of_ocaml-ocamlbuild js_of_ocaml-ppx \
			js_of_ocaml-lwt js_of_ocaml-compiler
JBUILDER_BUILD_PACKAGES=	js_of_ocaml-compiler js_of_ocaml js_of_ocaml-ocamlbuild js_of_ocaml-ppx js_of_ocaml-lwt

.include "options.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../devel/ocaml-ppx_deriving/buildlink3.mk"
.include "../../devel/ocaml-ppx_tools_versioned/buildlink3.mk"
.include "../../textproc/ocaml-uchar/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
