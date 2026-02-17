# $NetBSD: Makefile,v 1.5 2026/02/17 13:38:58 wiz Exp $

GITHUB_PROJECT=	eqaf
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.2
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirage/eqaf/
COMMENT=	Constant time equal function to avoid timing attacks
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-fmt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
