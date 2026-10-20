# $NetBSD: Makefile,v 1.9 2026/10/20 22:24:06 alnsn Exp $

DISTNAME=	${GITHUB_PROJECT}-0.5
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_PROJECT=	duff
GITHUB_TAG=	v${PKGVERSION_NOREV}
# 0.5 was retagged, remove on update
DIST_SUBDIR=	ocaml-duff-0.5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirage/duff/
COMMENT=	Library to generate ocaml-angstrom decoders and encoders
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

TEST_DEPENDS+=	ocaml-alcotest>=1.9.1:../../devel/ocaml-alcotest
TEST_DEPENDS+=	ocaml-bigstringaf-[0-9]*:../../devel/ocaml-bigstringaf

do-test:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		dune runtest --profile release test

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-fmt/buildlink3.mk"
.include "../../devel/ocaml-fpath/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
