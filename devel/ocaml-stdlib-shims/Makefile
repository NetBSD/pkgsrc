# $NetBSD: Makefile,v 1.1 2020/04/21 10:53:10 jaapb Exp $

GITHUB_PROJECT=	stdlib-shims
DISTNAME=	${GITHUB_PROJECT}-0.2.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/stdlib-shims/
COMMENT=	OCaml stdlib compatibility module
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
