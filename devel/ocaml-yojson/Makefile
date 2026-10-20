# $NetBSD: Makefile,v 1.18 2026/10/20 22:46:58 alnsn Exp $

GITHUB_PROJECT=	yojson
DISTNAME=	${GITHUB_PROJECT}-1.7.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjambon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mjambon/yojson/
COMMENT=	JSON parsing and pretty-printing library for OCaml
LICENSE=	modified-bsd

OCAML_USE_DUNE=		yes
INSTALLATION_DIRS+=	bin

TEST_DEPENDS+=	ocaml-alcotest>=1.9.1:../../devel/ocaml-alcotest

do-test:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		dune runtest --profile release

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-biniou/buildlink3.mk"
.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../textproc/ocaml-easy-format/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
