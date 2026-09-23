# $NetBSD: Makefile,v 1.24 2026/09/23 12:27:57 gdt Exp $

DISTNAME=	ocamlbuild-0.16.1
PKGREVISION=	3
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

# ocamlbuild not only uses findlib at build time, normally, but offers
# a way for the build tool to use findlib at runtime.
BUILDLINK_DEPMETHOD.ocaml-findlib?=	full

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
