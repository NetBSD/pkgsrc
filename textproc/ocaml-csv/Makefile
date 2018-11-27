# $NetBSD: Makefile,v 1.21 2018/11/27 19:49:45 jaapb Exp $

VERSION=	2.2
GITHUB_PROJECT=	ocaml-csv
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Chris00/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://csv.forge.ocamlcore.org/
COMMENT=	CSV library for OCaml
LICENSE=	gnu-lgpl-v2.1

#HAS_CONFIGURE=	yes
USE_LANGUAGES=	c

OCAML_USE_DUNE=	yes
DUNE_BUILD_PACKAGES=	csv
OPAM_INSTALL_FILES=	csv

.include "options.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
