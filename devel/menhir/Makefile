# $NetBSD: Makefile,v 1.28 2019/11/03 10:39:20 rillig Exp $
#

DISTNAME=	menhir-20181113
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.inria.fr/fpottier/${PKGBASE}/-/archive/${PKGVERSION_NOREV}/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://gallium.inria.fr/~fpottier/menhir/
COMMENT=	LR(1) parser generator in OCaml
LICENSE=	qpl-v1.0

USE_TOOLS+=	gmake
MAKE_JOBS_SAFE=	no

SUPERSEDES=		ocaml-menhir-[0-9]*
OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_REGISTER=	no

.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
MAKE_ENV+=	TARGET=native
.else
MAKE_ENV+=	TARGET=byte
.endif

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
MAKE_ENV+=	EGDIR=${EGDIR:Q} USE_OCAMLFIND=true \
		OCAML_SITELIBDIR=${OCAML_SITELIBDIR}

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
