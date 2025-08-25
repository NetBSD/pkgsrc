# $NetBSD: Makefile,v 1.7 2025/08/25 08:35:06 wiz Exp $

DISTNAME=	rresult-0.7.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/rresult/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	pkgsrc-users@NetBSD.org
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
