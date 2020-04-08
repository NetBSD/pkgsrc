# $NetBSD: Makefile,v 1.16 2020/04/08 08:56:37 jaapb Exp $

VERSION=	6.0
GITHUB_PROJECT=	ppx_tools
GITHUB_TAG=	${VERSION}+4.08.0
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-ppx/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-ppx/ppx_tools/
COMMENT=	Tools for authors of OCaml ppx rewriters
LICENSE=	mit

WRKSRC=			${WRKDIR}/${GITHUB_PROJECT}-${VERSION}-4.08.0
USE_LANGUAGES=		# none

OCAML_USE_DUNE=	yes

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=4.09.0 # this really needs 4.09

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
