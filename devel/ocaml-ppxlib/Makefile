# $NetBSD: Makefile,v 1.15 2022/05/24 18:59:31 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-0.26.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-ppx/}
GITHUB_PROJECT=	ppxlib
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-ppx/ppxlib/
COMMENT=	Base library and tools for ppx rewriters
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
USE_TOOLS+=	bash
OCAML_USE_DUNE=	yes

SUPERSEDES=	ocaml-ppx_ast-[0-9]* \
		ocaml-ppx_core-[0-9]* \
		ocaml-ppx_driver-[0-9]* \
		ocaml-ppx_metaquot-[0-9]* \
		ocaml-ppx_traverse_builtins-[0-9]* \
		ocaml-ppx_type_conv-[0-9]*

.include "../../devel/ocaml-compiler-libs/buildlink3.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../devel/ocaml-ppx_derivers/buildlink3.mk"
.include "../../devel/ocaml-sexplib0/buildlink3.mk"
.include "../../devel/ocaml-stdlib-shims/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
