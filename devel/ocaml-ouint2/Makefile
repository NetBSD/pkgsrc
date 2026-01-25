# $NetBSD: Makefile,v 1.2 2026/01/25 20:41:40 alnsn Exp $

DISTNAME=	ounit2-2.2.7
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=gildor478/}
GITHUB_PROJECT=	ounit
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocsigen/lwt_log/
COMMENT=	Unit test framework for OCaml
LICENSE=	mit

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	ounit2

TEST_TARGET=	test

.include "../../lang/ocaml/ocaml.mk"

.include "../../devel/ocaml-seq/buildlink3.mk"
.include "../../devel/ocaml-stdlib-shims/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
