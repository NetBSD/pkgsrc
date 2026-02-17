# $NetBSD: Makefile,v 1.7 2026/02/17 13:38:56 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	base_quickcheck
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/base_quickcheck/
COMMENT=	Randomised testing framework compatible with ocaml-base
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-ppx_base/buildlink3.mk"
.include "../../devel/ocaml-ppx_fields_conv/buildlink3.mk"
.include "../../devel/ocaml-ppx_let/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_message/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_value/buildlink3.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../devel/ocaml-splittable_random/buildlink3.mk"

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
