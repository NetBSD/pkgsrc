# $NetBSD: Makefile,v 1.6 2024/11/30 01:05:00 dholland Exp $

.include "../../devel/ocaml-dune/Makefile.common"

PKGNAME=	ocaml-dune-configurator-${DUNE_VERSION}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/dune/
COMMENT=	Configuration test library for Dune

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	dune-configurator

# needed for dune to see csexp, cf.
# https://github.com/ocaml/dune/issues/6156
post-extract:
	cd ${WRKSRC} && ${RM} -r vendor/csexp vendor/pp

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-csexp/buildlink3.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
