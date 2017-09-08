# $NetBSD: Makefile,v 1.9 2017/09/08 09:51:21 jaapb Exp $

VERSION=	0.9.0
GITHUB_PROJECT=	ppx_optcomp
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_optcomp/
COMMENT=	Optional compilation for OCaml
LICENSE=	apache-2.0

OCAML_USE_FINDLIB=	yes
OCAML_USE_JBUILDER=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-compiler-libs/buildlink3.mk"
.include "../../devel/ocaml-ppx_core/buildlink3.mk"
#.include "../../devel/ocaml-ppx_deriving/buildlink3.mk"
#.include "../../devel/ocaml-ppx_tools/buildlink3.mk"
#.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
