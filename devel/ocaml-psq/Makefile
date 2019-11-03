# $NetBSD: Makefile,v 1.2 2019/11/03 10:39:25 rillig Exp $

GITHUB_PROJECT=	psq
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.1.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=pqwy/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/pqwy/psq/
COMMENT=	Priority search queues for OCaml
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=		yes

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
