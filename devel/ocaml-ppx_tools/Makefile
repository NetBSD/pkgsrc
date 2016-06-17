# $NetBSD: Makefile,v 1.5 2016/06/17 11:02:09 jaapb Exp $

VERSION= 	5.0
GITHUB_PROJECT=	ppx_tools
GITHUB_TAG=	${VERSION}+4.03.0
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME= 	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=alainfrisch/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/alainfrisch/ppx_tools/
COMMENT=	Tools for authors of OCaml ppx rewriters
LICENSE=	mit

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${VERSION}-4.03.0
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake
OCAML_USE_FINDLIB=	yes

MAKE_JOBS_SAFE=	no

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
