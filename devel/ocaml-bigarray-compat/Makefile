# $NetBSD: Makefile,v 1.3 2022/05/02 13:23:44 jaapb Exp $

VERSION=	1.1.0
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
