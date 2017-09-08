# $NetBSD: Makefile,v 1.14 2017/09/08 09:51:26 jaapb Exp $
#

VERSION=	1.0.0
GITHUB_PROJECT=	ocaml-expat
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=whitequark/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/whitequark/ocaml-expat
COMMENT=	OCaml bindings for the expat library
LICENSE=	mit

USE_TOOLS+=	gmake
USE_LANGUAGES=	c
OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"

BUILD_TARGET=	all
.if (${OCAML_USE_OPT_COMPILER} == "yes")
BUILD_TARGET+=	allopt
.endif

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
