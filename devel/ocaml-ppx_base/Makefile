# $NetBSD: Makefile,v 1.1 2017/10/14 10:17:52 jaapb Exp $

GITHUB_PROJECT=	ppx_base
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.9.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_base/
COMMENT=	Base set of PPX rewriters
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

OCAML_USE_JBUILDER=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-ppx_compare/buildlink3.mk"
.include "../../devel/ocaml-ppx_driver/buildlink3.mk"
.include "../../devel/ocaml-ppx_enumerate/buildlink3.mk"
.include "../../devel/ocaml-ppx_hash/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_conv/buildlink3.mk"
.include "../../devel/ocaml-ppx_type_conv/buildlink3.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
