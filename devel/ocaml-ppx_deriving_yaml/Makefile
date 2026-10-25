# $NetBSD: Makefile,v 1.2 2026/10/25 01:42:59 alnsn Exp $

DISTNAME=	${GITHUB_PROJECT}-0.4.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=patricoferris/}
GITHUB_PROJECT=	ppx_deriving_yaml
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/patricoferris/ppx_deriving_yaml/
COMMENT=	OCaml types to Yaml types and back again
LICENSE=	isc

USE_LANGUAGES=		# none
OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	ppx_deriving_yaml

# TODO package ocaml-ezjsonm and add it to TEST_DEPENDS
do-test:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		dune runtest --profile release test

.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../textproc/ocaml-yaml/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
