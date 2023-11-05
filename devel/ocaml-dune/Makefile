# $NetBSD: Makefile,v 1.15 2023/11/05 21:26:41 jaapb Exp $

.include "Makefile.common"

PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/dune/
COMMENT=	Composable build system for OCaml

CONFLICTS=	ocaml-jbuilder-[0-9]*
SUPERSEDES=	ocaml-jbuilder-[0-9]*

USE_TOOLS+=		gmake
USE_LANGUAGES=		# none
UNLIMIT_RESOURCES+=	stacksize

HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--libdir ${PREFIX}/lib/ocaml --libdir ${PREFIX}/${OCAML_SITELIBDIR}

BUILD_TARGET=		release
MAKE_ENV+=		MAKE_JOBS=${MAKE_JOBS:U1}
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${OCAML_SITELIBDIR}/dune

OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_DIRS=	dune

.include "../../lang/ocaml/ocaml.mk"

.include "../../mk/bsd.pkg.mk"
