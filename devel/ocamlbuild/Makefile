# $NetBSD: Makefile,v 1.16 2022/05/24 18:51:51 jaapb Exp $

DISTNAME=	ocamlbuild-0.14.1
PKGREVISION=	1
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
INSTALL_TARGET=		findlib-install

MAKE_ENV=	CHECK_IF_PREINSTALLED=false OCAMLBUILD_BINDIR=${PREFIX}/bin \
		OCAMLBUILD_LIBDIR=${PREFIX}/${OCAML_SITELIBDIR}

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
