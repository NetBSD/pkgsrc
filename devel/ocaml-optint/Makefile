# $NetBSD: Makefile,v 1.9 2026/02/17 13:39:01 wiz Exp $

DISTNAME=	optint-0.2.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_PROJECT=	optint
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirage/optint/
COMMENT=	Library to provide fast integer (x64) or allocated int32 (x84)
LICENSE=	mit

OCAML_USE_DUNE=	yes

USE_LANGUAGES=	# none

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
