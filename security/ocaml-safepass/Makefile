# $NetBSD: Makefile,v 1.12 2026/02/17 13:39:12 wiz Exp $

GITHUB_PROJECT=	ocaml-safepass
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-3.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=darioteixeira/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/darioteixeira/ocaml-safepass/
COMMENT=	Safe storage library for user passwords in web applications
LICENSE=	gnu-lgpl-v2.1

OCAML_USE_DUNE=	yes

pre-build:
	${RUN} cd ${WRKSRC} && dune upgrade

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
