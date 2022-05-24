# $NetBSD: Makefile,v 1.15 2022/05/24 18:59:35 jaapb Exp $

DISTNAME=	markup-1.0.3
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=aantron/}
GITHUB_PROJECT=	markup.ml
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/aantron/markup.ml/
COMMENT=	Error-recovering streaming HTML5 and XML parsers for OCaml
LICENSE=	mit

#HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	markup
OPAM_INSTALL_FILES=	markup

#do-configure:
#	${RUN} cd ${WRKSRC} && ocaml src/configure.ml

.include "options.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../textproc/ocaml-uutf/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
