# $NetBSD: Makefile,v 1.23 2019/03/05 16:53:49 jaapb Exp $

DISTNAME=	cppo-1.6.5
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjambon/}
GITHUB_PROJECT=	cppo
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
#HOMEPAGE=	http://mjambon.com/cppo.html
COMMENT=	C-style preprocessor for OCaml
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
#USE_TOOLS+=	gmake

OCAML_USE_DUNE=	yes

INSTALLATION_DIRS+=	bin ${OCAML_SITELIBDIR}/cppo_ocamlbuild \
			share/doc/ocaml-cppo share/doc/ocaml-cppo_ocamlbuild
OCAML_FINDLIB_DIRS+=    cppo_ocamlbuild
DUNE_BUILD_PACKAGES=	cppo cppo_ocamlbuild
OPAM_INSTALL_FILES=	cppo cppo_ocamlbuild

.include "../../mk/ocaml.mk"

.include "../../devel/ocamlbuild/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocamlbuild?=        full
.include "../../mk/bsd.pkg.mk"
