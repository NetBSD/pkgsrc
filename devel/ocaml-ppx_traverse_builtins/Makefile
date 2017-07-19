# $NetBSD: Makefile,v 1.1 2017/07/19 12:30:02 jaapb Exp $

VERSION=	0.9.0
GITHUB_PROJECT=	ppx_traverse_builtins
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_traverse_builtins/
COMMENT=	Metaquotations for ppx_ast
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

OCAML_USE_JBUILDER=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
