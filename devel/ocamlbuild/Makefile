# $NetBSD: Makefile,v 1.23 2026/03/01 12:38:34 gdt Exp $

DISTNAME=	ocamlbuild-0.16.1
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
