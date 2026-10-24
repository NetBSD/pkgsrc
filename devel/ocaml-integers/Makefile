# $NetBSD: Makefile,v 1.2 2026/10/24 17:20:19 alnsn Exp $

DISTNAME=	integers-0.7.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=yallop/}
GITHUB_PROJECT=	ocaml-integers
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yallop/ocaml-integers/
COMMENT=	Various signed and unsigned integer types for OCaml
LICENSE=	mit

USE_LANGUAGES=		c
OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	integers
OPAM_INSTALL_FILES=	integers

TEST_TARGET=	test

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-stdlib-shims/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
