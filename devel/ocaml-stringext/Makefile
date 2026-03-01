# $NetBSD: Makefile,v 1.7 2026/03/01 12:38:33 gdt Exp $

GITHUB_PROJECT=	stringext
DISTNAME=	${GITHUB_PROJECT}-1.6.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rgrinberg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rgrinberg/stringext/
COMMENT=	Extra string functions for OCaml
LICENSE=	mit

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
