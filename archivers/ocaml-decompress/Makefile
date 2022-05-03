# $NetBSD: Makefile,v 1.3 2022/05/03 19:45:12 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-1.4.3
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_PROJECT=	decompress
GITHUB_TAG=	v${PKGVERSION_NOREV}

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
