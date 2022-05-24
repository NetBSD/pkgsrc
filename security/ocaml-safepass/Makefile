# $NetBSD: Makefile,v 1.9 2022/05/24 18:51:54 jaapb Exp $

GITHUB_PROJECT=	ocaml-safepass
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-3.0
PKGREVISION=	6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=darioteixeira/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/darioteixeira/ocaml-safepass/
COMMENT=	Safe storage library for user passwords in web applications
LICENSE=	gnu-lgpl-v2.1

OCAML_USE_DUNE=	yes

pre-build:
	${RUN} cd ${WRKSRC} && dune upgrade

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
