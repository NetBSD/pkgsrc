# $NetBSD: Makefile,v 1.2 2016/02/23 15:03:49 joerg Exp $

GITHUB_PROJECT=	ppx_deriving
DISTNAME=	${GITHUB_PROJECT}-3.1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=whitequark/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=whitequark/ppx_deriving/}
COMMENT=	Type-driven code generation for OCaml
LICENSE=	mit

DEPENDS+=	ocaml-ppx_tools-[0-9]*:../../devel/ocaml-ppx_tools

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
OCAML_USE_FINDLIB=	yes

BUILD_TARGET=	build

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
