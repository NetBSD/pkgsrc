# $NetBSD: Makefile,v 1.5 2022/05/24 18:59:32 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-0.3.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}
GITHUB_PROJECT=	stdlib-shims

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/stdlib-shims/
COMMENT=	OCaml stdlib compatibility module
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
