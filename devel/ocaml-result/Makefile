# $NetBSD: Makefile,v 1.6 2018/04/09 09:36:08 jaapb Exp $

GITHUB_PROJECT=	result
DISTNAME=	${GITHUB_PROJECT}-1.3
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/result/
COMMENT=	OCaml compatibility library for Result module
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
OCAML_USE_JBUILDER=	yes
INSTALLATION_DIRS+=	${OCAML_SITELIBDIR}/result share/doc/result

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
