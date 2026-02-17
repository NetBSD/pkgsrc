# $NetBSD: Makefile,v 1.7 2026/02/17 13:38:57 wiz Exp $

GITHUB_PROJECT=	csexp
DISTNAME=	${GITHUB_PROJECT}-1.5.2
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-dune/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-dune/csexp/
COMMENT=	Canonical S-expressions library for OCaml
LICENSE=	mit

USE_LANGUAGES=	# none

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
