# $NetBSD: Makefile,v 1.1 2016/02/06 13:39:49 jaapb Exp $

VERSION= 0.99.3
GITHUB_PROJECT=	ppx_tools
DISTNAME=	${GITHUB_PROJECT}_${VERSION}
PKGNAME= ocaml-${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	devel
GITHUB_TAG= ${GITHUB_PROJECT}_${VERSION}
MASTER_SITES=	${MASTER_SITE_GITHUB:=diml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=alainfrisch/ppx_tools/}
COMMENT=	Tools for authors of OCaml ppx rewriters
LICENSE=	mit

WRKSRC=		${WRKDIR}/ppx_tools-ppx_tools_0.99.3
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake
OCAML_USE_FINDLIB=	yes

MAKE_JOBS_SAFE=	no

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
