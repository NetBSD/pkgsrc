# $NetBSD: Makefile,v 1.29 2019/07/01 04:08:35 ryoon Exp $

VERSION=	2.0.3
GITHUB_PROJECT=	opam
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://opam.ocaml.org/
COMMENT=	OCaml package manager
LICENSE=	gnu-lgpl-v3
MAKE_JOBS_SAFE=	no

HAS_CONFIGURE=		yes
OCAML_USE_DUNE=	yes

OCAML_FINDLIB_DIRS+=	opam-installer
OPAM_INSTALL_FILES=	opam opam-installer

.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../devel/ocaml-extlib/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../devel/ocamlgraph/buildlink3.mk"
.include "../../misc/dose3/buildlink3.mk" # with ocamlgraph option
.include "../../misc/ocaml-cudf/buildlink3.mk"
.include "../../misc/ocaml-opam-file-format/buildlink3.mk"
.include "../../textproc/ocaml-jsonm/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
