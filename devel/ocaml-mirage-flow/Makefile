# $NetBSD: Makefile,v 1.1 2022/06/13 08:12:02 jaapb Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	${GITHUB_PROJECT}-3.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_PROJECT=	mirage-flow
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/mirage-flow/
COMMENT=	Flow implementations for Mirage
LICENSE=	isc

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

DUNE_BUILD_PACKAGES=	mirage-flow mirage-flow-unix mirage-flow-combinators
OPAM_INSTALL_FILES=	${DUNE_BUILD_PACKAGES}
OCAML_FINDLIB_DIRS=	${DUNE_BUILD_PACKAGES}

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-cstruct/buildlink3.mk"
.include "../../devel/ocaml-fmt/buildlink3.mk"
.include "../../devel/ocaml-logs/buildlink3.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../time/ocaml-mirage-clock/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
