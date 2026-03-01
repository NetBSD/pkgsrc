# $NetBSD: Makefile,v 1.19 2026/03/01 12:38:21 gdt Exp $

VERSION=	3.5.0
GITHUB_PROJECT=	ocaml-base64
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-base64/
COMMENT=	Base64 encoding and decoding in OCaml
LICENSE=	isc

OCAML_USE_OPAM=	yes
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
