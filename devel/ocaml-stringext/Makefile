# $NetBSD: Makefile,v 1.2 2020/01/24 16:27:41 jaapb Exp $

GITHUB_PROJECT=	stringext
DISTNAME=	${GITHUB_PROJECT}-1.6.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rgrinberg/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/rgrinberg/stringext/
COMMENT=	Extra string functions for OCaml
LICENSE=	mit

OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
