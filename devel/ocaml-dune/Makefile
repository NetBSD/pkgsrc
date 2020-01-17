# $NetBSD: Makefile,v 1.8 2020/01/17 10:42:42 jaapb Exp $

GITHUB_PROJECT=	dune
DISTNAME=	${GITHUB_PROJECT}-2.1.3
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/dune/
COMMENT=	Composable build system for OCaml
LICENSE=	apache-2.0

CONFLICTS=	ocaml-jbuilder-[0-9]*
SUPERSEDES=	ocaml-jbuilder-[0-9]*

USE_TOOLS+=		gmake
USE_LANGUAGES=		# none
UNLIMIT_RESOURCES+=	stacksize

BUILD_TARGET=		release
MAKE_ENV+=		MAKE_JOBS=${MAKE_JOBS:U1}
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${OCAML_SITELIBDIR}/dune

OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_DIRS=	dune \
			dune-action-plugin \
			dune-build-info \
			dune-configurator \
			dune-glob \
			dune-private-libs \
			stublibs
OCAML_USE_OPAM=		yes
OPAM_INSTALL_FILES=	dune-glob \
			dune-action-plugin \
			dune-build-info \
			dune \
			dune-private-libs \
			dune-configurator

post-build:
	${RUN} cd ${WRKSRC} && ./dune.exe build -p dune,dune-action-plugin,dune-build-info,dune-configurator,dune-glob,dune-private-libs @install

.include "../../mk/ocaml.mk"

.include "../../mk/bsd.pkg.mk"
