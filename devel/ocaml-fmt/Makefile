# $NetBSD: Makefile,v 1.3 2019/05/29 03:23:28 mef Exp $

DISTNAME=	fmt-0.8.5
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
OCAML_USE_OPAM=	yes

.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../devel/ocaml-cmdliner/buildlink3.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../misc/ocaml-topkg/buildlink3.mk"
.include "../../textproc/ocaml-uchar/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
