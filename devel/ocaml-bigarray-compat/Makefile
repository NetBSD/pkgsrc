# $NetBSD: Makefile,v 1.1 2020/01/24 16:20:47 jaapb Exp $

VERSION=	1.0.0
GITHUB_PROJECT=	bigarray-compat
DISTNAME=	ocaml-${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/bigarray-compat/
COMMENT=	Compatibility package for the BigArray library in OCaml
LICENSE=	isc

OCAML_USE_OPAM=	yes
OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
