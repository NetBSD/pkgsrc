# $NetBSD: Makefile,v 1.3 2020/12/11 08:02:22 jaapb Exp $

GITHUB_PROJECT=	ppx_bench
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.14.1
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
