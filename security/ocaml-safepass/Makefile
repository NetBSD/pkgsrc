# $NetBSD: Makefile,v 1.7 2020/01/29 16:33:18 jaapb Exp $

GITHUB_PROJECT=	ocaml-safepass
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-3.0
PKGREVISION=	4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=darioteixeira/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/darioteixeira/ocaml-safepass/
COMMENT=	Safe storage library for user passwords in web applications
LICENSE=	gnu-lgpl-v2.1

OCAML_USE_DUNE=	yes

pre-build:
	${RUN} cd ${WRKSRC} && dune upgrade

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
