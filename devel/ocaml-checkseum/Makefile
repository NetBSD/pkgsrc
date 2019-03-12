# $NetBSD: Makefile,v 1.1 2019/03/12 17:57:08 jaapb Exp $

GITHUB_PROJECT=	checkseum
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.0.3
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/checkseum/
COMMENT=	Library for Adler-32, CRC32 and CRC32-C algorithms
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../devel/ocaml-fmt/buildlink3.mk"
.include "../../devel/ocaml-optint/buildlink3.mk"
.include "../../devel/ocaml-rresult/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
