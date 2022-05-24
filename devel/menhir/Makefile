# $NetBSD: Makefile,v 1.33 2022/05/24 18:59:21 jaapb Exp $
#

DISTNAME=	menhir-20220210
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.inria.fr/fpottier/${PKGBASE}/-/archive/${PKGVERSION_NOREV}/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://gallium.inria.fr/~fpottier/menhir/
COMMENT=	LR(1) parser generator in OCaml
LICENSE=	qpl-v1.0

SUPERSEDES=		ocaml-menhir-[0-9]*
OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	menhir menhirLib menhirSdk
OPAM_INSTALL_FILES=	${DUNE_BUILD_PACKAGES}

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
