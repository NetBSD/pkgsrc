# $NetBSD: Makefile,v 1.7 2017/07/11 14:19:22 jaapb Exp $

VERSION= 	5.0
GITHUB_PROJECT=	ppx_tools
GITHUB_TAG=	49c08e2
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME= 	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=alainfrisch/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/alainfrisch/ppx_tools/
COMMENT=	Tools for authors of OCaml ppx rewriters
LICENSE=	mit

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-49c08e2e4ea8fef88692cd1dcc1b38a9133f17ac
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake
OCAML_USE_FINDLIB=	yes

MAKE_JOBS_SAFE=	no

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
