# $NetBSD: Makefile,v 1.2 2019/03/05 16:11:03 jaapb Exp $

GITHUB_PROJECT=	dune
#GITHUB_TAG=	${PKGVERSION_NOREV:S/_/+/}
DISTNAME=	${GITHUB_PROJECT}-1.7.3
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

BUILD_TARGET=	default
MAKE_ENV+=	MAKE_JOBS=${MAKE_JOBS:U1}
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${OCAML_SITELIBDIR}/dune

OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_DIRS=	dune stublibs
OCAML_USE_OPAM=	yes

.include "../../mk/ocaml.mk"

.include "../../mk/bsd.pkg.mk"
