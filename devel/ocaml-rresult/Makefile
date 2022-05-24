# $NetBSD: Makefile,v 1.6 2022/05/24 18:59:31 jaapb Exp $

DISTNAME=	rresult-0.7.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/rresult/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://erratique.ch/software/rresult/
COMMENT=	Declarative handling of results and errors in OCaml
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=		yes

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocaml-compiler-libs/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
