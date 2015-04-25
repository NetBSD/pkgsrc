# $NetBSD: Makefile,v 1.4 2015/04/25 14:20:37 tnn Exp $

DISTNAME=	ocamlgraph-1.8.5
PKGNAME=	${DISTNAME} # avoid prefixing with ocaml-
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://ocamlgraph.lri.fr/download/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://ocamlgraph.lri.fr/
COMMENT=	Graph library for OCaml
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
INSTALL_TARGET=	install-findlib
OCAML_USE_FINDLIB=	yes

.include "options.mk"

MAKE_ENV+=	USE_LABLGTK="${USE_LABLGTK}"

.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
MAKE_ENV+=	OCAMLBEST="opt"
.else
MAKE_ENV+=	OCAMLBEST="byte"
.endif

post-install:
.if ${USE_LABLGTK} == "yes"
.if ${OCAML_USE_OPT_COMPILER} == "yes"
	${INSTALL_PROGRAM} ${WRKSRC}/editor/editor.opt ${DESTDIR}${PREFIX}/bin/graph-editor
	${INSTALL_PROGRAM} ${WRKSRC}/dgraph/dgraph.opt ${DESTDIR}${PREFIX}/bin/graph-viewer
.else
	${INSTALL_PROGRAM} ${WKRSRC}/editor/editor.byte ${DESTDIR}${PREFIX}/bin/graph-editor
	${INSTALL_PROGRAM} ${WKRSRC}/dgraph/dgraph.byte ${DESTDIR}${PREFIX}/bin/graph-viewer
.endif
.endif

.include "../../mk/bsd.pkg.mk"
