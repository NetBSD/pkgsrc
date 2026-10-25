# $NetBSD: Makefile,v 1.3 2026/10/25 18:23:50 alnsn Exp $

.include "../../devel/ocaml-dune/Makefile.common"

PKGNAME=	ocaml-dune-site-${DUNE_VERSION}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/dune/
COMMENT=	Embed locations information inside executable and libraries

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	dune-site dune-private-libs

# TODO Either install dune-private-libs by uncommening the line
# below or create a new devel/ocaml-dune-private-libs package
# if any dependent package wants dune's private libs.
#OPAM_INSTALL_FILES=	${DUNE_BUILD_PACKAGES}

BUILDLINK_API_DEPENDS.ocaml-dune+=	ocaml-dune>=${DUNE_VERSION}

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-csexp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
