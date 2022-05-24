# $NetBSD: Makefile,v 1.5 2022/05/24 18:59:23 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-6.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_PROJECT=	ocaml-cstruct
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-cstruct/
COMMENT=	Map OCaml arrays onto C-like structs
LICENSE=	isc

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	cstruct cstruct-unix cstruct-sexp
OPAM_INSTALL_FILES=	cstruct cstruct-unix cstruct-sexp

.include "options.mk"
.include "../../devel/ocaml-fmt/buildlink3.mk"
.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
