# $NetBSD: Makefile,v 1.4 2019/11/01 19:41:46 maya Exp $

GITHUB_PROJECT=	dune
#GITHUB_TAG=	${PKGVERSION_NOREV:S/_/+/}
DISTNAME=	${GITHUB_PROJECT}-1.11.4
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/dune/
COMMENT=	Composable build system for OCaml
LICENSE=	apache-2.0

CONFLICTS=	ocaml-jbuilder-[0-9]*
SUPERSEDES=	ocaml-jbuilder-[0-9]*

USE_TOOLS+=	gmake
USE_LANGUAGES=	# none
UNLIMIT_RESOURCES+=	stacksize

BUILD_TARGET=	release
MAKE_ENV+=	MAKE_JOBS=${MAKE_JOBS:U1}
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${OCAML_SITELIBDIR}/dune

OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_DIRS=	dune stublibs
OCAML_USE_OPAM=	yes

.include "../../mk/ocaml.mk"

.include "../../mk/bsd.pkg.mk"
