# $NetBSD: Makefile,v 1.4 2026/03/01 12:38:24 gdt Exp $

PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
DISTNAME=	${GITHUB_PROJECT}-0.3.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=dinosaure/}
GITHUB_PROJECT=	hxd
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
