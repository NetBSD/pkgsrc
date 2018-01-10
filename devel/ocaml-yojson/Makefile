# $NetBSD: Makefile,v 1.4 2018/01/10 16:53:11 jaapb Exp $

GITHUB_PROJECT=	yojson
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-1.3.3
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjambon/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mjambon/yojson/
COMMENT=	JSON parsing and pretty-printing library for OCaml
LICENSE=	modified-bsd

MAKE_JOBS_SAFE=	no
USE_TOOLS+=	gmake
BUILD_TARGET=	META all
OCAML_USE_FINDLIB=	yes
INSTALLATION_DIRS+=	bin

.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET+=	opt
.endif

.include "../../devel/ocaml-biniou/buildlink3.mk"
.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../textproc/ocaml-easy-format/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
