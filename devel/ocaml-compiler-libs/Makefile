# $NetBSD: Makefile,v 1.14 2022/05/24 18:59:23 jaapb Exp $

VERSION=	0.12.4
GITHUB_PROJECT=	ocaml-compiler-libs
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ocaml-compiler-libs/
COMMENT=	Repackaging of OCaml compiler libraries
LICENSE=	apache-2.0

OCAML_USE_DUNE=	yes

OCAML_TOPKG_NAME=	${GITHUB_PROJECT}

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
