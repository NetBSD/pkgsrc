# $NetBSD: Makefile,v 1.13 2019/03/05 17:34:16 jaapb Exp $

VERSION=	3.1.0
GITHUB_PROJECT=	ocaml-base64
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-base64/
COMMENT=	Base64 encoding and decoding in OCaml
LICENSE=	isc

OCAML_USE_OPAM=	yes
OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
