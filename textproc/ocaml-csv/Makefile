# $NetBSD: Makefile,v 1.27 2022/05/24 18:59:35 jaapb Exp $

VERSION=	2.4
PKGREVISION=	1
GITHUB_PROJECT=	ocaml-csv
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Chris00/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/Chris00/ocaml-csv/
COMMENT=	CSV library for OCaml
LICENSE=	gnu-lgpl-v2.1

#HAS_CONFIGURE=	yes
USE_LANGUAGES=	c

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	csv
OPAM_INSTALL_FILES=	${DUNE_BUILD_PACKAGES}
OCAML_FINDLIB_DIRS=	${DUNE_BUILD_PACKAGES}

.include "options.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
