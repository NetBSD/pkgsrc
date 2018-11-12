# $NetBSD: Makefile,v 1.12 2018/11/12 16:10:21 jaapb Exp $

VERSION= 	5.1
GITHUB_PROJECT=	ppx_tools
GITHUB_TAG=	${VERSION}+4.06.0
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME= 	ocaml-${DISTNAME}
PKGREVISION= 	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-ppx/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-ppx/ppx_tools/
COMMENT=	Tools for authors of OCaml ppx rewriters
LICENSE=	mit

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${VERSION}-4.06.0
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake
OCAML_USE_FINDLIB=	yes

MAKE_JOBS_SAFE=	no

BUILDLINK_API_DEPENDS.ocaml+=   ocaml>=4.06.0 # this really needs 4.06

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
