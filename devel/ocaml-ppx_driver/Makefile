# $NetBSD: Makefile,v 1.9 2017/09/08 09:51:21 jaapb Exp $

VERSION=	0.9.1
GITHUB_PROJECT=	ppx_driver
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_driver/
COMMENT=	Feature-full driver for OCaml AST transformers
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
OCAML_USE_FINDLIB=	yes
OCAML_USE_JBUILDER=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-ppx_core/buildlink3.mk"
.include "../../devel/ocaml-ppx_optcomp/buildlink3.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
