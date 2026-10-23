# $NetBSD: Makefile,v 1.1 2026/10/23 23:17:50 alnsn Exp $

DISTNAME=	parmap-1.2.5
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rdicosmo/}
GITHUB_PROJECT=	parmap
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rdicosmo.github.io/parmap/
COMMENT=	Minimalistic library to exploit multicore architecture for OCaml
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=		gmake
OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	parmap
OPAM_INSTALL_FILES=	parmap

TEST_TARGET=		test

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
