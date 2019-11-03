# $NetBSD: Makefile,v 1.11 2019/11/03 10:39:26 rillig Exp $

GITHUB_PROJECT=	result
DISTNAME=	${GITHUB_PROJECT}-1.3
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/result/
COMMENT=	OCaml compatibility library for Result module
LICENSE=	modified-bsd

USE_LANGUAGES=		# none
OCAML_USE_DUNE=		yes
INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/result share/doc/result

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
