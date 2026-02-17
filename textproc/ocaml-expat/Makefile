# $NetBSD: Makefile,v 1.23 2026/02/17 13:39:12 wiz Exp $
#

VERSION=	1.0.0
GITHUB_PROJECT=	ocaml-expat
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=whitequark/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/whitequark/ocaml-expat
COMMENT=	OCaml bindings for the expat library
LICENSE=	mit

USE_TOOLS+=		gmake
USE_LANGUAGES=		c
OCAML_USE_FINDLIB=	yes

.include "../../lang/ocaml/ocaml.mk"

BUILD_TARGET=	all
.if (${OCAML_USE_OPT_COMPILER} == "yes")
BUILD_TARGET+=	allopt
.endif

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
