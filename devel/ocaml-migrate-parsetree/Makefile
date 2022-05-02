# $NetBSD: Makefile,v 1.20 2022/05/02 13:13:34 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-2.3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-ppx/}
GITHUB_PROJECT=	ocaml-migrate-parsetree
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-ppx/ocaml-migrate-parsetree/
COMMENT=	Migrate parse trees between versions of OCaml
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c
OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_DIRS=	${GITHUB_PROJECT}
OCAML_USE_DUNE=		yes
OPAM_INSTALL_FILES=	${GITHUB_PROJECT}

.include "../../mk/ocaml.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
