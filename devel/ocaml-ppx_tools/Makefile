# $NetBSD: Makefile,v 1.4 2016/06/09 06:23:39 wiz Exp $

VERSION= 5.0
GITHUB_PROJECT=	ppx_tools
GITHUB_TAG=	5.0+4.03.0
PKGNAME= ocaml-${GITHUB_PROJECT}-${VERSION}
DISTNAME=	${GITHUB_PROJECT}_${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=alainfrisch/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/alainfrisch/ppx_tools/
COMMENT=	Tools for authors of OCaml ppx rewriters
LICENSE=	mit

WRKSRC=		${WRKDIR}/ppx_tools-${VERSION}-4.03.0
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake
OCAML_USE_FINDLIB=	yes

MAKE_JOBS_SAFE=	no

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
