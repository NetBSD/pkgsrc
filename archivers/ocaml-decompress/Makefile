# $NetBSD: Makefile,v 1.1 2019/03/12 18:00:02 jaapb Exp $

GITHUB_PROJECT=	decompress
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.8.1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/decompress/
COMMENT=	Pure OCaml implementation of Zlib
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-checkseum/buildlink3.mk"
.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../devel/ocaml-optint/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
