# $NetBSD: Makefile,v 1.2 2018/01/10 16:53:09 jaapb Exp $

VERSION=	0.9.0
GITHUB_PROJECT=	ppx_compare
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGREVISION=	1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_compare/
COMMENT=	Generation of comparison functions from types
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

OCAML_USE_JBUILDER=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-ppx_core/buildlink3.mk"
.include "../../devel/ocaml-ppx_driver/buildlink3.mk"
.include "../../devel/ocaml-ppx_metaquot/buildlink3.mk"
.include "../../devel/ocaml-ppx_type_conv/buildlink3.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
