# $NetBSD: Makefile,v 1.1 2020/12/09 11:10:47 jaapb Exp $

GITHUB_PROJECT=	csexp
DISTNAME=	${GITHUB_PROJECT}-1.3.2
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-dune/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-dune/csexp/
COMMENT=	Canonical S-expressions library for OCaml
LICENSE=	mit

USE_LANGUAGES=	# none

OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
