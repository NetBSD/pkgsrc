# $NetBSD: Makefile,v 1.2 2016/05/05 15:58:58 jaapb Exp $

DISTNAME=	ocamlbuild-0.9.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=ocaml/ocamlbuild/}
COMMENT=	Build system for OCaml
LICENSE=	gnu-lgpl-v2

CONFLICTS+=	ocaml<=4.02.3

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

OCAML_USE_FINDLIB=	yes
INSTALL_TARGET=	findlib-install

MAKE_ENV=	CHECK_IF_PREINSTALLED=false

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
