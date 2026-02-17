# $NetBSD: Makefile,v 1.17 2026/02/17 13:39:07 wiz Exp $

GITHUB_PROJECT=	result
DISTNAME=	${GITHUB_PROJECT}-1.5
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/result/
COMMENT=	OCaml compatibility library for Result module
LICENSE=	modified-bsd

USE_LANGUAGES=		# none
OCAML_USE_DUNE=		yes
INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/result share/doc/result

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
