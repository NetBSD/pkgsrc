# $NetBSD: Makefile,v 1.13 2026/10/25 18:23:50 alnsn Exp $

.include "../../devel/ocaml-dune/Makefile.common"

PKGNAME=	ocaml-dune-configurator-${DUNE_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/dune/
COMMENT=	Configuration test library for Dune

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	dune-configurator

# needed for dune to see csexp, cf.
# https://github.com/ocaml/dune/issues/6156
post-extract:
	cd ${WRKSRC} && ${RM} -r vendor/csexp vendor/pp

BUILDLINK_API_DEPENDS.ocaml-dune+=	ocaml-dune>=${DUNE_VERSION}

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-csexp/buildlink3.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
