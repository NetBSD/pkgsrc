# $NetBSD: Makefile,v 1.16 2025/08/25 08:35:06 wiz Exp $

GITHUB_PROJECT=	result
DISTNAME=	${GITHUB_PROJECT}-1.5
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
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
