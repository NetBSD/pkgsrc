# $NetBSD: Makefile,v 1.2 2026/10/24 21:43:20 alnsn Exp $

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

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-csexp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
