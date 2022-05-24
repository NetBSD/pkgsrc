# $NetBSD: Makefile,v 1.4 2022/05/24 18:51:48 jaapb Exp $

GITHUB_PROJECT=	csexp
DISTNAME=	${GITHUB_PROJECT}-1.5.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-dune/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-dune/csexp/
COMMENT=	Canonical S-expressions library for OCaml
LICENSE=	mit

USE_LANGUAGES=	# none

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
