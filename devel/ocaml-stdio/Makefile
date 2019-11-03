# $NetBSD: Makefile,v 1.11 2019/11/03 10:39:26 rillig Exp $

GITHUB_PROJECT=	stdio
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.12.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/stdio/
COMMENT=	Standard IO library for OCaml
LICENSE=	apache-2.0

USE_LANGUAGES=		# none
OCAML_USE_FINDLIB=	yes
OCAML_USE_DUNE=		yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
