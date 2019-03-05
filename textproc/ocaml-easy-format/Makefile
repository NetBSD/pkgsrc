# $NetBSD: Makefile,v 1.8 2019/03/05 17:35:52 jaapb Exp $

GITHUB_PROJECT=	easy-format
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-1.3.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjambon/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mjambon/easy-format/
COMMENT=	Pretty-printing library for OCaml
LICENSE=	modified-bsd

OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
