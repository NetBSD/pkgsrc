# $NetBSD: Makefile,v 1.4 2022/05/04 16:07:51 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	ppx_let
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_let/
COMMENT=	Monadic let-bindings for OCaml
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-ppx_here/buildlink3.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
