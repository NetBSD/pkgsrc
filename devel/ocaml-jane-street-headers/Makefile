# $NetBSD: Makefile,v 1.1 2019/03/13 11:35:47 jaapb Exp $

GITHUB_PROJECT=	jane-street-headers
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.12.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/jane-street-headers/
COMMENT=	Jane Street header files for OCaml
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
