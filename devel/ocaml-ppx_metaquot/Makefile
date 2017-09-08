# $NetBSD: Makefile,v 1.2 2017/09/08 09:51:21 jaapb Exp $

VERSION=	0.9.0
GITHUB_PROJECT=	ppx_metaquot
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGREVISION=	1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_metaquot/
COMMENT=	Metaquotations for ppx_ast
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

OCAML_USE_JBUILDER=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-ppx_core/buildlink3.mk"
.include "../../devel/ocaml-ppx_driver/buildlink3.mk"
.include "../../devel/ocaml-ppx_traverse_builtins/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
