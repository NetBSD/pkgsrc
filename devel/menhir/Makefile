# $NetBSD: Makefile,v 1.15 2016/02/06 12:10:33 jaapb Exp $
#

DISTNAME=	menhir-20140422
PKGREVISION= 2
CATEGORIES=	devel
MASTER_SITES=	http://cristal.inria.fr/~fpottier/menhir/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://cristal.inria.fr/~fpottier/menhir/
COMMENT=	LR(1) parser generator in OCaml
LICENSE=	qpl-v1.0

USE_TOOLS+=		gmake
MAKE_JOBS_SAFE=	no

SUPERSEDES=	ocaml-menhir-[0-9]*
OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
MAKE_ENV+=	TARGET=native
.else
MAKE_ENV+=	TARGET=byte
.endif

EGDIR=				${PREFIX}/share/examples/${PKGBASE}
MAKE_ENV+=		EGDIR=${EGDIR:Q} USE_OCAMLFIND=true \
	OCAML_SITELIBDIR=${OCAML_SITELIBDIR}

.include "../../mk/bsd.pkg.mk"
