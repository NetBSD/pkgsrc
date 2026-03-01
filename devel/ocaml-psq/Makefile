# $NetBSD: Makefile,v 1.8 2026/03/01 12:38:32 gdt Exp $

DISTNAME=	${GITHUB_PROJECT}-0.2.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=pqwy/}
GITHUB_PROJECT=	psq
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pqwy/psq/
COMMENT=	Priority search queues for OCaml
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_DUNE=		yes

.include "../../devel/ocaml-seq/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
