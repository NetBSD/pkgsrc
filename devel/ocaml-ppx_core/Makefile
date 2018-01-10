# $NetBSD: Makefile,v 1.11 2018/01/10 16:03:53 jaapb Exp $

VERSION=	0.9.2
GITHUB_PROJECT=	ppx_core
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_core/
COMMENT=	Standard library for OCaml ppx rewriters
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
OCAML_USE_FINDLIB=	yes
OCAML_USE_JBUILDER=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-compiler-libs/buildlink3.mk"
.include "../../devel/ocaml-ppx_ast/buildlink3.mk"
.include "../../devel/ocaml-ppx_traverse_builtins/buildlink3.mk"
.include "../../devel/ocaml-stdio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
