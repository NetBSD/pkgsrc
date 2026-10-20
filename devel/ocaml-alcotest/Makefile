# $NetBSD: Makefile,v 1.1 2026/10/20 20:55:07 alnsn Exp $

DISTNAME=	alcotest-1.9.1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_PROJECT=	alcotest
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirage/alcotest/
COMMENT=	Lightweight and colourful test framework for OCaml
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	alcotest
OPAM_INSTALL_FILES=	alcotest

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-astring/buildlink3.mk"
.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../devel/ocaml-fmt/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../devel/ocaml-stdlib-shims/buildlink3.mk"
.include "../../textproc/ocaml-uutf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
