# $NetBSD: Makefile,v 1.9 2018/11/27 17:20:09 jaapb Exp $

GITHUB_PROJECT=	markup.ml
GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	markup-0.8.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=aantron/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/aantron/markup.ml/
COMMENT=	Error-recovering streaming HTML5 and XML parsers for OCaml
LICENSE=	2-clause-bsd

#HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

OCAML_USE_DUNE=	yes
DUNE_BUILD_PACKAGES=	markup
OPAM_INSTALL_FILES=	markup

#do-configure:
#	${RUN} cd ${WRKSRC} && ocaml src/configure.ml

.include "options.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../textproc/ocaml-uutf/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
