# $NetBSD: Makefile,v 1.4 2022/05/24 18:51:51 jaapb Exp $

GITHUB_PROJECT=	psq
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.1.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
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
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
