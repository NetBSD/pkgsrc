# $NetBSD: Makefile,v 1.5 2025/08/25 08:34:55 wiz Exp $

VERSION=	1.1.0
GITHUB_PROJECT=	bigarray-compat
DISTNAME=	ocaml-${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirage/bigarray-compat/
COMMENT=	Compatibility package for the BigArray library in OCaml
LICENSE=	isc

OCAML_USE_OPAM=	yes
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
