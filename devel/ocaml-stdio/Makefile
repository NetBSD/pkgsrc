# $NetBSD: Makefile,v 1.15 2022/05/24 18:59:32 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	stdio
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/stdio/
COMMENT=	Standard IO library for OCaml
LICENSE=	apache-2.0

USE_LANGUAGES=		# none
OCAML_USE_FINDLIB=	yes
OCAML_USE_DUNE=		yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
