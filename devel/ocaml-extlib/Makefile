# $NetBSD: Makefile,v 1.19 2019/08/27 16:04:02 schmonz Exp $

VERSION=	1.7.6
PKGREVISION=	1
GITHUB_PROJECT=	ocaml-extlib
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ygrek/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ygrek/ocaml-extlib
COMMENT=	Alternative standard library for OCaml
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake

MAKE_JOBS_SAFE=	no

OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET=	build
.else
BUILD_TARGET=	all
.endif

.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
