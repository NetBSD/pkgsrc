# $NetBSD: Makefile,v 1.5 2022/05/24 18:59:32 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	splittable_random
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/splittable_random/
COMMENT=	PRNG that can be split into independent streams
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-ppx_assert/buildlink3.mk"
.include "../../devel/ocaml-ppx_bench/buildlink3.mk"
.include "../../devel/ocaml-ppx_inline_test/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_message/buildlink3.mk"

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
