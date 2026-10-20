# $NetBSD: Makefile,v 1.20 2026/10/20 23:34:26 alnsn Exp $

VERSION=	3.5.0
GITHUB_PROJECT=	ocaml-base64
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-base64/
COMMENT=	Base64 encoding and decoding in OCaml
LICENSE=	isc

OCAML_USE_OPAM=	yes
OCAML_USE_DUNE=	yes

TEST_DEPENDS+=	ocaml-alcotest>=1.9.1:../../devel/ocaml-alcotest
TEST_DEPENDS+=	ocaml-bos-[0-9]*:../../devel/ocaml-bos
TEST_DEPENDS+=	ocaml-rresult-[0-9]*:../../devel/ocaml-rresult

do-test:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		dune runtest --profile release

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
