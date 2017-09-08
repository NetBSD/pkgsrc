# $NetBSD: Makefile,v 1.11 2017/09/08 12:21:36 jaapb Exp $

GITHUB_PROJECT=	ppx_deriving
DISTNAME=	${GITHUB_PROJECT}-4.2
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-ppx/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-ppx/ppx_deriving/
COMMENT=	Type-driven code generation for OCaml
LICENSE=	mit

DEPENDS+=	ocaml-ppx_tools-[0-9]*:../../devel/ocaml-ppx_tools

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
OCAML_USE_FINDLIB=	yes

BUILD_TARGET=	build

.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../devel/ocaml-ppx_derivers/buildlink3.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
