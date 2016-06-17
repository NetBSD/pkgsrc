# $NetBSD: Makefile,v 1.6 2016/06/17 11:04:30 jaapb Exp $

GITHUB_PROJECT=	ppx_deriving
DISTNAME=	${GITHUB_PROJECT}-3.3
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=whitequark/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/whitequark/ppx_deriving/
COMMENT=	Type-driven code generation for OCaml
LICENSE=	mit

DEPENDS+=	ocaml-ppx_tools-[0-9]*:../../devel/ocaml-ppx_tools

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
OCAML_USE_FINDLIB=	yes

BUILD_TARGET=	build

.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
