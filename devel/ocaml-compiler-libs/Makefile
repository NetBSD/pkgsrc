# $NetBSD: Makefile,v 1.1 2017/07/21 10:20:04 jaapb Exp $

VERSION=	0.9.0
GITHUB_PROJECT=	ocaml-compiler-libs
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ocaml-compiler-libs/
COMMENT=	Repackaging of OCaml compiler libraries
LICENSE=	apache-2.0

OCAML_USE_FINDLIB=	yes
OCAML_USE_JBUILDER=	yes

OCAML_TOPKG_NAME=	${GITHUB_PROJECT}

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
