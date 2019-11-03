# $NetBSD: Makefile,v 1.16 2019/11/03 10:39:24 rillig Exp $

GITHUB_PROJECT=	ppx_sexp_conv
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.12.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_sexp_conv/
COMMENT=	Generation of S-expression conversion functions from type definitions
LICENSE=	apache-2.0

USE_LANGUAGES=		# none
OCAML_USE_FINDLIB=	yes
OCAML_USE_DUNE=		yes

.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
