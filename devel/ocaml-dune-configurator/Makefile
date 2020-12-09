# $NetBSD: Makefile,v 1.1 2020/12/09 10:52:17 jaapb Exp $

.include "../../devel/ocaml-dune/Makefile.common"

PKGNAME=	ocaml-dune-configurator-${DUNE_VERSION}
CATEGORIES=	devel

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/dune/
COMMENT=	Configuration test library for Dune

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	dune-configurator

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-csexp/buildlink3.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
