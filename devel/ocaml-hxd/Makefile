# $NetBSD: Makefile,v 1.1 2022/06/20 08:16:58 jaapb Exp $

PKGNAME=	ocaml-${DISTNAME}
DISTNAME=	${GITHUB_PROJECT}-0.3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=dinosaure/}
GITHUB_PROJECT=	hxd
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/dinosaure/hxd/
COMMENT=	Hexdump in OCaml
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

DUNE_BUILD_PACKAGES=	hxd
OPAM_INSTALL_FILES=	${DUNE_BUILD_PACKAGES}
OCAML_FINDLIB_DIRS=	${DUNE_BUILD_PACKAGES}

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../devel/ocaml-dune-configurator/buildlink3.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
