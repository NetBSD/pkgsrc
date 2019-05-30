# $NetBSD: Makefile,v 1.2 2019/05/30 10:00:07 jaapb Exp $

DISTNAME=	rresult-0.6.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/rresult/releases/
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://erratique.ch/software/rresult/
COMMENT=	Declarative handling of results and errors in OCaml
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_TOPKG=	yes
OCAML_USE_OPAM=	yes

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocaml-compiler-libs/buildlink3.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
