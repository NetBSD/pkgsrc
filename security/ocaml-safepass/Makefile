# $NetBSD: Makefile,v 1.4 2018/11/12 16:10:26 jaapb Exp $

GITHUB_PROJECT=	ocaml-safepass
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-3.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=darioteixeira/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/darioteixeira/ocaml-safepass/
COMMENT=	Safe storage library for user passwords in web applications
LICENSE=	gnu-lgpl-v2.1

OCAML_USE_JBUILDER=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
