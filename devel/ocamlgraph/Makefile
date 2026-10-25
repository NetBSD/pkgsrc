# $NetBSD: Makefile,v 1.81 2026/10/25 00:46:16 alnsn Exp $

DISTNAME=	ocamlgraph-2.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=backtracking/}
GITHUB_PROJECT=	ocamlgraph
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/backtracking/ocamlgraph/
COMMENT=	Graph library for OCaml
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		# none
OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	ocamlgraph
OPAM_INSTALL_FILES=	${DUNE_BUILD_PACKAGES}

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
