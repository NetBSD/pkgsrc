# $NetBSD: Makefile,v 1.26 2021/03/08 08:12:50 jaapb Exp $

DISTNAME=	cppo-1.6.6
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-community/}
GITHUB_PROJECT=	cppo
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-community/cppo/
COMMENT=	C-style preprocessor for OCaml
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
#USE_TOOLS+=	gmake

OCAML_USE_DUNE=	yes

INSTALLATION_DIRS+=	bin ${OCAML_SITELIBDIR}/cppo_ocamlbuild \
			share/doc/ocaml-cppo share/doc/ocaml-cppo_ocamlbuild
OCAML_FINDLIB_DIRS+=	cppo_ocamlbuild
DUNE_BUILD_PACKAGES=	cppo cppo_ocamlbuild
OPAM_INSTALL_FILES=	cppo cppo_ocamlbuild

.include "../../mk/ocaml.mk"

.include "../../devel/ocamlbuild/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocamlbuild=        full
.include "../../mk/bsd.pkg.mk"
