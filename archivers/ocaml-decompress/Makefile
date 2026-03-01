# $NetBSD: Makefile,v 1.7 2026/03/01 12:38:18 gdt Exp $

DISTNAME=	${GITHUB_PROJECT}-1.4.3
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_PROJECT=	decompress
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirage/decompress/
COMMENT=	Pure OCaml implementation of Zlib
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-checkseum/buildlink3.mk"
.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../devel/ocaml-optint/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
