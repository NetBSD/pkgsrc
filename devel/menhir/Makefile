# $NetBSD: Makefile,v 1.38 2026/03/01 12:38:20 gdt Exp $

DISTNAME=	menhir-20260112
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.inria.fr/fpottier/${PKGBASE}/-/archive/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gallium.inria.fr/~fpottier/menhir/
COMMENT=	LR(1) parser generator in OCaml
LICENSE=	qpl-v1.0

SUPERSEDES=		ocaml-menhir-[0-9]*
OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	menhir menhirGLR menhirLib menhirSdk
OPAM_INSTALL_FILES=	${DUNE_BUILD_PACKAGES}

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
