# $NetBSD: Makefile,v 1.4 2022/05/24 18:51:51 jaapb Exp $

GITHUB_PROJECT=	stringext
DISTNAME=	${GITHUB_PROJECT}-1.6.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rgrinberg/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/rgrinberg/stringext/
COMMENT=	Extra string functions for OCaml
LICENSE=	mit

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
