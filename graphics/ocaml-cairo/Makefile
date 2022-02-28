# $NetBSD: Makefile,v 1.14 2022/02/28 18:26:19 gdt Exp $

GITHUB_PROJECT=	ocaml-cairo
DISTNAME=	${GITHUB_PROJECT}-0.6.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=Chris00/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/Chris00/ocaml-cairo/
COMMENT=	Bindings for OCaml to the cairo library
LICENSE=	gnu-lgpl-v3

OCAML_USE_DUNE=		yes
OCAML_FINDLIB_DIRS=	cairo2
OPAM_INSTALL_FILES=	${OCAML_FINDLIB_DIRS}
DUNE_BUILD_PACKAGES=	${OCAML_FINDLIB_DIRS}

# (Se options.mk.)  Upstream says that lablgtk is required, but it is
# not.
#   https://github.com/Chris00/ocaml-cairo/issues/29

.include "options.mk"
.include "../../mk/ocaml.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/ocaml-dune-configurator/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
