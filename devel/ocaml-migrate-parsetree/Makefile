# $NetBSD: Makefile,v 1.8 2018/04/04 19:12:53 jaapb Exp $

GITHUB_PROJECT=	ocaml-migrate-parsetree
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-1.0.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=let-def/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/let-def/ocaml-migrate-parsetree/
COMMENT=	Migrate parse trees between versions of OCaml
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c
OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_DIRS=	${GITHUB_PROJECT}
OCAML_USE_JBUILDER=	yes
OPAM_INSTALL_FILES=	${GITHUB_PROJECT}

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
