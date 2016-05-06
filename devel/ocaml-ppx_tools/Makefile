# $NetBSD: Makefile,v 1.3 2016/05/06 11:26:29 jaapb Exp $

VERSION= 5.0
GITHUB_PROJECT=	ppx_tools
GITHUB_TAG=	5.0+4.03.0
PKGNAME= ocaml-${GITHUB_PROJECT}-${VERSION}
DISTNAME=	${GITHUB_PROJECT}_${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=alainfrisch/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=alainfrisch/ppx_tools/}
COMMENT=	Tools for authors of OCaml ppx rewriters
LICENSE=	mit

WRKSRC=		${WRKDIR}/ppx_tools-${VERSION}-4.03.0
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake
OCAML_USE_FINDLIB=	yes

MAKE_JOBS_SAFE=	no

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
