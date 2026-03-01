# $NetBSD: Makefile,v 1.62 2026/03/01 12:38:36 gdt Exp $

DISTNAME=	opam-2.1.3
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}
GITHUB_PROJECT=	opam

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opam.ocaml.org/
COMMENT=	OCaml package manager
LICENSE=	gnu-lgpl-v3

DEPENDS+=	curl-[0-9]*:../../www/curl

MAKE_JOBS_SAFE=	no

USE_LANGUAGES+=	c++

HAS_CONFIGURE=	yes
OCAML_USE_DUNE=	yes

OCAML_FINDLIB_DIRS+=	opam-installer opam-solver
OPAM_INSTALL_FILES=	opam opam-installer opam-solver

.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../devel/ocamlgraph/buildlink3.mk"
.include "../../misc/dose3/buildlink3.mk" # with ocamlgraph option
.include "../../misc/ocaml-cudf/buildlink3.mk"
.include "../../misc/ocaml-opam-file-format/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
