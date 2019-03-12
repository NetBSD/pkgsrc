# $NetBSD: Makefile,v 1.1 2019/03/12 18:52:03 jaapb Exp $

GITHUB_PROJECT=	ppx_bench
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.12.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_bench/
COMMENT=	Syntax extension for writing in-line benchmarks in OCaml code
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../devel/ocaml-ppx_inline_test/buildlink3.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
