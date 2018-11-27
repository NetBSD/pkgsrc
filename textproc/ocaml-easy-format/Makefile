# $NetBSD: Makefile,v 1.7 2018/11/27 22:45:00 jaapb Exp $

GITHUB_PROJECT=	easy-format
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-1.3.1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjambon/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mjambon/easy-format/
COMMENT=	Pretty-printing library for OCaml
LICENSE=	modified-bsd

OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
