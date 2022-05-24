# $NetBSD: Makefile,v 1.2 2022/05/24 18:59:21 jaapb Exp $
#

DISTNAME=	${GITHUB_PROJECT}-0.0.0.3693
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}
GITHUB_PROJECT=	js_of_ocaml-ocamlbuild
GITHUB_TAG=	852302c

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://ocsigen.org/js_of_ocaml/
COMMENT=	Compiler of OCaml bytecode to Javascript
LICENSE=	gnu-lgpl-v2

USE_TOOLS=	bash

OCAML_USE_FINDLIB=	yes
OCAML_USE_DUNE=		yes

DUNE_INSTALL_PACKAGES=	js_of_ocaml-ocamlbuild
OPAM_INSTALL_FILES=	${DUNE_INSTALL_PACKAGES}
OCAML_FINDLIB_DIRS=	${DUNE_INSTALL_PACKAGES}

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-852302c8f35b946e2ec275c529a79e46d8749be6

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
