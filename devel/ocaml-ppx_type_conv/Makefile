# $NetBSD: Makefile,v 1.9 2017/09/08 09:51:22 jaapb Exp $

VERSION=	0.9.0
GITHUB_PROJECT=	ppx_type_conv
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_type_conv/
COMMENT=	Support library for type-driven code generators
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
OCAML_USE_FINDLIB=	yes
OCAML_USE_JBUILDER=	yes

.include "../../mk/ocaml.mk"
#.include "../../devel/ocaml-oasis/buildlink3.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../devel/ocaml-ppx_deriving/buildlink3.mk"
.include "../../devel/ocaml-ppx_driver/buildlink3.mk"
.include "../../devel/ocaml-ppx_metaquot/buildlink3.mk"
#.include "../../devel/ocaml-ppx_tools/buildlink3.mk"
#.include "../../misc/ocaml-opam/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
