# $NetBSD: Makefile,v 1.8 2026/10/20 23:12:04 alnsn Exp $

DISTNAME=	ocaml-${GITHUB_PROJECT}-0.4.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=hannesm/}
GITHUB_PROJECT=	domain-name
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hannesm/domain-name/
COMMENT=	RFC 1035 Internet domain name library for OCaml
LICENSE=	isc

OCAML_USE_DUNE=		yes

TEST_DEPENDS+=	ocaml-alcotest>=1.9.1:../../devel/ocaml-alcotest

do-test:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		dune runtest --profile release

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
