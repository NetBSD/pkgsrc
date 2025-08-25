# $NetBSD: Makefile,v 1.5 2025/08/25 08:35:07 wiz Exp $

GITHUB_PROJECT=	stringext
DISTNAME=	${GITHUB_PROJECT}-1.6.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rgrinberg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rgrinberg/stringext/
COMMENT=	Extra string functions for OCaml
LICENSE=	mit

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
