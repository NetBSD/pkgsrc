# $NetBSD: Makefile,v 1.5 2026/03/01 12:38:25 gdt Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.2
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	ocaml_intrinsics
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ocaml_intrinsics/
COMMENT=	Library of intrinsics for OCaml
LICENSE=	mit

USE_LANGUAGES=		# none
OCAML_USE_DUNE=		yes
OPAM_INSTALL_FILES=	${GITHUB_PROJECT}
OCAML_FINDLIB_DIRS=	${GITHUB_PROJECT}

.include "../../devel/ocaml-dune-configurator/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
