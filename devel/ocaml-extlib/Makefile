# $NetBSD: Makefile,v 1.23 2022/05/24 18:51:49 jaapb Exp $

VERSION=	1.7.8
GITHUB_PROJECT=	ocaml-extlib
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ygrek/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ygrek/ocaml-extlib
COMMENT=	Alternative standard library for OCaml
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake

OCAML_USE_FINDLIB=	yes

.include "../../lang/ocaml/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET=	build
.else
BUILD_TARGET=	all
.endif

.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
