# $NetBSD: Makefile,v 1.10 2016/06/25 14:32:00 jaapb Exp $
#

DISTNAME=	ocaml-expat-0.9.1
PKGREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	http://mmzeeman.home.xs4all.nl/ocaml/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://mmzeeman.home.xs4all.nl/ocaml/
COMMENT=	OCaml bindings for the expat library
LICENSE=	mit

USE_TOOLS+=	gmake
USE_LANGUAGES=	c
BUILD_TARGET=	all

OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"

.if (${OCAML_USE_OPT_COMPILER} == "yes")
BUILD_TARGET+=	allopt expat.cmxs
.endif

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
