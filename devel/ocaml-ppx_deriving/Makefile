# $NetBSD: Makefile,v 1.24 2025/08/25 08:35:02 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-5.2.1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-ppx/}
GITHUB_PROJECT=	ppx_deriving
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-ppx/ppx_deriving/
COMMENT=	Type-driven code generation for OCaml
LICENSE=	mit

USE_LANGUAGES=	c
OCAML_USE_DUNE=	yes

.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../devel/ocaml-ppx_derivers/buildlink3.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
