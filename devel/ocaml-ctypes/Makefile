# $NetBSD: Makefile,v 1.2 2026/10/24 17:42:13 alnsn Exp $

DISTNAME=	ctypes-0.21.1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=yallop/}
GITHUB_PROJECT=	ocaml-ctypes
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yallop/ocaml-ctypes/
COMMENT=	Library for binding to C libraries using pure OCaml
LICENSE=	mit

USE_LANGUAGES=		c
OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	ctypes ctypes-foreign
OPAM_INSTALL_FILES=	${DUNE_BUILD_PACKAGES}

TEST_DEPENDS+=	ocaml-ounit2>=2.2.0:../../devel/ocaml-ounit2
TEST_TARGET=	test

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/ocaml-bigarray-compat/buildlink3.mk"
.include "../../devel/ocaml-dune-configurator/buildlink3.mk"
.include "../../devel/ocaml-integers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
