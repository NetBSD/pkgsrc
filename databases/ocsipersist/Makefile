# $NetBSD: Makefile,v 1.1 2022/05/20 06:47:28 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-1.1.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocsigen/}
GITHUB_PROJECT=	ocsipersist
GITHUB_TAG=	${PKGVERSION_NOREV}
#DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/ocsipersist/
COMMENT=	Key/value storage libraries for OCaml
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	ocsigen>=3.0.0:../../www/ocsigen

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	ocsipersist ocsipersist-lib
OPAM_INSTALL_FILES=	${DUNE_BUILD_PACKAGES}
OCAML_FINDLIB_DIRS=	${DUNE_BUILD_PACKAGES}


.include "options.mk"
.include "../../mk/ocaml.mk"
.include "../../databases/ocaml-dbm/buildlink3.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/ocaml-lwt_ppx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
