# $NetBSD: Makefile,v 1.9 2025/08/25 08:34:58 wiz Exp $

DISTNAME=	fmt-0.9.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/fmt/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://erratique.ch/software/fmt/
COMMENT=	OCaml combinators for pretty-printing functions
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=		yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
