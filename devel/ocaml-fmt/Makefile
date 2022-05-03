# $NetBSD: Makefile,v 1.7 2022/05/03 19:24:37 jaapb Exp $

DISTNAME=	fmt-0.9.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/fmt/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://erratique.ch/software/fmt/
COMMENT=	OCaml combinators for pretty-printing functions
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=		yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
