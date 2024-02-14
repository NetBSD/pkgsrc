# $NetBSD: Makefile,v 1.31 2024/02/14 15:45:09 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-0.6.4
PKGREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=Chris00/}
GITHUB_PROJECT=	ocaml-cairo

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/Chris00/ocaml-cairo/
COMMENT=	Bindings for OCaml to the cairo library
LICENSE=	gnu-lgpl-v3

OCAML_USE_DUNE=		yes
OCAML_FINDLIB_DIRS=	cairo2
OPAM_INSTALL_FILES=	${OCAML_FINDLIB_DIRS}
DUNE_BUILD_PACKAGES=	${OCAML_FINDLIB_DIRS}

USE_TOOLS+=	pkg-config
# ocaml-cairo doesn't find pkg-config
# https://github.com/Chris00/ocaml-cairo/issues/35
# seems related but has not solution
# override detection:
CAIRO_CFLAGS=	pkg-config --cflags cairo
CAIRO_LIBS=	pkg-config --libs cairo
MAKE_ENV+=	CAIRO_CFLAGS=${CAIRO_CFLAGS:sh:Q}
MAKE_ENV+=	CAIRO_LIBS=${CAIRO_LIBS:sh:Q}
# but this isn't enough, because it leads to:
# Error: Rule failed to generate the following targets:
# - src/cairo_ocaml.h
# so create this file manually and remove the existing logic
# to avoid an error during configure (see patch-src_dune)
#
# TODO: enable freetype2
pre-configure:
	cp ${WRKSRC}/src/cairo_ocaml.h.p ${WRKSRC}/src/cairo_ocaml.h

# (See options.mk.)  Upstream says that lablgtk is required, but it is
# not.
#   https://github.com/Chris00/ocaml-cairo/issues/29

.include "options.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/ocaml-dune-configurator/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
