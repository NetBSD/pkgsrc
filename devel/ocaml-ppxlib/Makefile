# $NetBSD: Makefile,v 1.5 2018/11/12 16:10:22 jaapb Exp $

GITHUB_PROJECT=	ppxlib
GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.3.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-ppx/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-ppx/ppxlib/
COMMENT=	Base library and tools for ppx rewriters
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
USE_TOOLS+=	bash
OCAML_USE_JBUILDER=	yes

SUPERSEDES=	ocaml-ppx_ast-[0-9]* \
	ocaml-ppx_core-[0-9]* \
	ocaml-ppx_driver-[0-9]* \
	ocaml-ppx_metaquot-[0-9]* \
	ocaml-ppx_traverse_builtins-[0-9]* \
	ocaml-ppx_type_conv-[0-9]*

.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-compiler-libs/buildlink3.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../devel/ocaml-ppx_derivers/buildlink3.mk"
.include "../../devel/ocaml-stdio/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
