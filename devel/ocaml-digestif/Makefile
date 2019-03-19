# $NetBSD: Makefile,v 1.1 2019/03/19 11:15:12 jaapb Exp $

GITHUB_PROJECT=	digestif
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.7.1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/digestif/
COMMENT=	Simple hash algorithms in OCaml
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-eqaf/buildlink3.mk"
.include "../../devel/ocaml-fmt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
