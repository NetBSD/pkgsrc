# $NetBSD: Makefile,v 1.13 2021/03/08 08:13:07 jaapb Exp $

GITHUB_PROJECT=	markup.ml
GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	markup-0.8.2
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=aantron/}

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
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
