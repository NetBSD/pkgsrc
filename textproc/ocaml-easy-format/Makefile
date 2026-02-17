# $NetBSD: Makefile,v 1.13 2026/02/17 13:39:12 wiz Exp $

GITHUB_PROJECT=	easy-format
DISTNAME=	${GITHUB_PROJECT}-1.3.2
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjambon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mjambon/easy-format/
COMMENT=	Pretty-printing library for OCaml
LICENSE=	modified-bsd

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
