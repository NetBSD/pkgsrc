# $NetBSD: Makefile,v 1.7 2026/02/17 13:39:00 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-0.3.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=pqwy/}
GITHUB_PROJECT=	lru
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pqwy/lru/
COMMENT=	Scalable LRU caches for OCaml
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_DUNE=		yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-psq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
