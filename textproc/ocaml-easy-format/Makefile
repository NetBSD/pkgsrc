# $NetBSD: Makefile,v 1.4 2018/04/13 13:55:37 jaapb Exp $

GITHUB_PROJECT=	easy-format
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-1.2.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjambon/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mjambon/easy-format/
COMMENT=	Pretty-printing library for OCaml
LICENSE=	modified-bsd

USE_TOOLS+=	gmake
BUILD_TARGET=	all
OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET+=	opt
.endif

.include "../../mk/bsd.pkg.mk"
