# $NetBSD: Makefile,v 1.32 2026/03/01 12:38:22 gdt Exp $

DISTNAME=	cppo-1.6.8
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-community/}
GITHUB_PROJECT=	cppo
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
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

.include "../../lang/ocaml/ocaml.mk"

.include "../../devel/ocamlbuild/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocamlbuild=        full
.include "../../mk/bsd.pkg.mk"
