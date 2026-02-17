# $NetBSD: Makefile,v 1.3 2026/02/17 13:39:11 wiz Exp $

PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
DISTNAME=	${GITHUB_PROJECT}-0.0.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=dinosaure/}
GITHUB_PROJECT=	mimic
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dinosaure/mimic/
COMMENT=	Dynamic instantiation of transmission protocols
LICENSE=	isc

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

DUNE_BUILD_PACKAGES=	mimic
OPAM_INSTALL_FILES=	${DUNE_BUILD_PACKAGES}
OCAML_FINDLIB_DIRS=	${DUNE_BUILD_PACKAGES}

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-fmt/buildlink3.mk"
.include "../../devel/ocaml-logs/buildlink3.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/ocaml-mirage-flow/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
