# $NetBSD: Makefile,v 1.21 2026/03/01 23:37:31 gdt Exp $

# Updating to 2.2.0 is blocked on
#   https://github.com/ocaml/opam-file-format/issues/64

# Updating to 2.2.0 is blocked on a dependency cycle created by
# upstream dropping Makefile support.

VERSION=	2.1.6
GITHUB_PROJECT=	opam-file-format
GITHUB_TAG=	${VERSION:S/_/-/}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opam.ocaml.org/
COMMENT=	Parser and printer for the opam file syntax
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=		gmake
# 2.2.0 OCAML_USE_DUNE=		yes
OCAML_USE_FINDLIB=	yes

# 2.2.0 TOOL_DEPENDS devle/menhir

INSTALL_ENV+=	LIBDIR=${PREFIX}/${OCAML_SITELIBDIR}

.include "../../lang/ocaml/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET=	all
.else
BUILD_TARGET=	byte
.endif

.include "../../mk/bsd.pkg.mk"
