# $NetBSD: Makefile,v 1.11 2022/05/24 18:51:55 jaapb Exp $

GITHUB_PROJECT=	easy-format
DISTNAME=	${GITHUB_PROJECT}-1.3.2
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjambon/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mjambon/easy-format/
COMMENT=	Pretty-printing library for OCaml
LICENSE=	modified-bsd

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
