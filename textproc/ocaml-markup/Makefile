# $NetBSD: Makefile,v 1.17 2026/02/17 13:39:13 wiz Exp $

DISTNAME=	markup-1.0.3
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=aantron/}
GITHUB_PROJECT=	markup.ml
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
