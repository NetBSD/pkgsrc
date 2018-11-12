# $NetBSD: Makefile,v 1.8 2018/11/12 16:10:19 jaapb Exp $

VERSION=	0.11.0
GITHUB_PROJECT=	ocaml-compiler-libs
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ocaml-compiler-libs/
COMMENT=	Repackaging of OCaml compiler libraries
LICENSE=	apache-2.0

OCAML_USE_FINDLIB=	yes
OCAML_USE_JBUILDER=	yes
OCAML_USE_OPAM=		yes

OCAML_TOPKG_NAME=	${GITHUB_PROJECT}

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
