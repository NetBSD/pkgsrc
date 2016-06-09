# $NetBSD: Makefile,v 1.3 2016/06/09 06:23:39 wiz Exp $

DISTNAME=	ocamlbuild-0.9.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/ocamlbuild/
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
