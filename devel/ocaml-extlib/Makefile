# $NetBSD: Makefile,v 1.4 2016/02/06 12:10:33 jaapb Exp $

DISTNAME=	extlib-1.6.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://ocaml-extlib.googlecode.com/files/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ocaml-extlib/
COMMENT=	Alternative standard library for OCaml
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake
MAKE_JOBS_SAFE=	no

OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"

BUILD_TARGET=	all
.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET+=	opt
.endif

.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
