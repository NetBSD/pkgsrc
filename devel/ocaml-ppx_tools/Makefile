# $NetBSD: Makefile,v 1.14 2019/08/01 20:31:47 jperkin Exp $

VERSION= 	5.3
GITHUB_PROJECT=	ppx_tools
GITHUB_TAG=	${VERSION}+4.08.0
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME= 	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-ppx/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-ppx/ppx_tools/
COMMENT=	Tools for authors of OCaml ppx rewriters
LICENSE=	mit

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${VERSION}-4.08.0
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake
OCAML_USE_FINDLIB=	yes

MAKE_JOBS_SAFE=	no

#BUILDLINK_API_DEPENDS.ocaml+=   ocaml>=4.08.0 # this really needs 4.08

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
