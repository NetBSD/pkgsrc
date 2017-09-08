# $NetBSD: Makefile,v 1.4 2017/09/08 09:51:22 jaapb Exp $

GITHUB_PROJECT=	result
DISTNAME=	${GITHUB_PROJECT}-1.2
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/result/
COMMENT=	OCaml compatibility library for Result module
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"
BUILD_TARGET=	byte
.if (${OCAML_USE_OPT_COMPILER} == "yes")
BUILD_TARGET+=	native
.endif
BUILD_TARGET+=	result.install

.include "../../mk/bsd.pkg.mk"
