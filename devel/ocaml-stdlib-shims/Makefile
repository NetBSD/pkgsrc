# $NetBSD: Makefile,v 1.7 2026/02/17 13:39:08 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-0.3.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}
GITHUB_PROJECT=	stdlib-shims

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/stdlib-shims/
COMMENT=	OCaml stdlib compatibility module
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
